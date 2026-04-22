#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <string_view>
#include <vector>
#include "transaction.h"

class BankAccount {
public:
    explicit BankAccount(std::string_view owner_id);
    virtual ~BankAccount() = default;

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual double get_balance() const = 0;

    void add_transaction(const Transaction& tx);
    const std::vector<Transaction>& get_history() const;
    std::string_view get_owner_id() const;

protected:
    double balance_;
    std::string owner_id_;
    std::vector<Transaction> history_;
};

#endif // BANK_ACCOUNT_H