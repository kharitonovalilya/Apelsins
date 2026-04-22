#include "bankaccount.h"

BankAccount::BankAccount(std::string_view owner_id)
    : balance_(0.0)
    , owner_id_(owner_id)
{}

void BankAccount::add_transaction(const Transaction& tx) {
    history_.push_back(tx);
}

const std::vector<Transaction>& BankAccount::get_history() const {
    return history_;
}

std::string_view BankAccount::get_owner_id() const {
    return owner_id_;
}