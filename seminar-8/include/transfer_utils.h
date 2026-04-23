#pragma once

#include "bankaccount.h"
#include "currency.h"
#include "transaction.h"
#include <optional>
#include <string>
#include <variant>

std::optional<Transaction>
execute_transfer(BankAccount &src, BankAccount &dst, double amount,
                 const std::variant<CurrencyCode, std::string> &currency,
                 const CurrencyConverter &converter);