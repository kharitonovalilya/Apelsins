#include "savingsaccount.h"
#include "exceptions.h"
#include "currency.h"
#include <chrono>

SavingsAccount::SavingsAccount(std::string_view owner_id, double initial_balance)
    : BankAccount(owner_id)
{
    if (initial_balance < 0) {
        throw std::invalid_argument("Initial balance cannot be negative");
    }
    balance_ = initial_balance;
}

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) return;
    balance_ += amount;

    Transaction tx("external", owner_id_, amount, CurrencyCode::USD);
    add_transaction(tx);
}

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0) return;
    if (amount > balance_) {
        throw InsufficientFundsException("Insufficient funds in SavingsAccount");
    }
    balance_ -= amount;

    Transaction tx(owner_id_, "external", amount, CurrencyCode::USD);
    add_transaction(tx);
}

double SavingsAccount::get_balance() const {
    return balance_;
}

void SavingsAccount::set_interest_rate(double rate) {
    interest_rate_ = rate;
}

void SavingsAccount::apply_interest() {
    if (interest_rate_ > 0.0) {
        double interest = balance_ * interest_rate_ / 100.0;
        deposit(interest);
    }
}