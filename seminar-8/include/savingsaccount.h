#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "bankaccount.h"
#include <stdexcept>

class SavingsAccount : public BankAccount {
public:
    explicit SavingsAccount(std::string_view owner_id, double initial_balance = 0.0);
    ~SavingsAccount() override = default;

    void deposit(double amount) override;
    void withdraw(double amount) override;
    double get_balance() const override;

    void set_interest_rate(double rate);
    void apply_interest();

private:
    double interest_rate_ = 0.0;
};

#endif // SAVINGS_ACCOUNT_H