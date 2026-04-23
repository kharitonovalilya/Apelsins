#include "checkingaccount.h"
#include "exceptions.h"
#include "currency.h"
#include <chrono>

CheckingAccount::CheckingAccount(std::string_view owner_id, double initial_balance, double daily_limit)
    : BankAccount(owner_id)
    , daily_limit_(daily_limit)
    , withdrawn_today_(0.0)
    , last_reset_time_(std::chrono::system_clock::now())
{
    if (initial_balance < 0) {
        throw std::invalid_argument("Initial balance cannot be negative");
    }
    if (daily_limit < 0) {
        throw std::invalid_argument("Daily limit cannot be negative");
    }
    balance_ = initial_balance;
}

void CheckingAccount::reset_if_needed() {
    auto now = std::chrono::system_clock::now();
    auto last_day = std::chrono::duration_cast<std::chrono::hours>(last_reset_time_.time_since_epoch()).count() / 24;
    auto now_day = std::chrono::duration_cast<std::chrono::hours>(now.time_since_epoch()).count() / 24;
    if (now_day > last_day) {
        withdrawn_today_ = 0.0;
        last_reset_time_ = now;
    }
}

void CheckingAccount::deposit(double amount) {
    if (amount <= 0) return;
    balance_ += amount;

    Transaction tx("external", owner_id_, amount, CurrencyCode::USD);
    add_transaction(tx);
}

void CheckingAccount::withdraw(double amount) {
    if (amount <= 0) return;
    reset_if_needed();

    if (amount > balance_) {
        throw InsufficientFundsException("Insufficient funds in CheckingAccount");
    }
    if (withdrawn_today_ + amount > daily_limit_) {
        throw TransactionLimitExceededException("Daily transaction limit would be exceeded");
    }

    balance_ -= amount;
    withdrawn_today_ += amount;

    Transaction tx(owner_id_, "external", amount, CurrencyCode::USD);
    add_transaction(tx);
}

double CheckingAccount::get_balance() const {
    return balance_;
}