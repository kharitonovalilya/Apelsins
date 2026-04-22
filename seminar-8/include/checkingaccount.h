#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "bankaccount.h"
#include <chrono>
#include <stdexcept>

class CheckingAccount : public BankAccount {
public:
    explicit CheckingAccount(std::string_view owner_id, double initial_balance = 0.0, double daily_limit = 500.0);
    ~CheckingAccount() override = default;

    void deposit(double amount) override;
    void withdraw(double amount) override;
    double get_balance() const override;

private:
    double daily_limit_;
    double withdrawn_today_;
    std::chrono::system_clock::time_point last_reset_time_;

    void reset_if_needed();
};

#endif // CHECKING_ACCOUNT_H