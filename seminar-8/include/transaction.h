#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "currency.h"
#include <ctime>
#include <string>

class Transaction {
private:
  std::string from_id;
  std::string to_id;
  double amount;
  CurrencyCode currency;
  std::time_t timestamp;

public:
  explicit Transaction(std::string_view from, std::string_view to,
                       double amount, CurrencyCode currency);
  [[nodiscard]] const std::string &get_from() const { return from_id; }
  [[nodiscard]] const std::string &get_to() const { return to_id; }
  [[nodiscard]] double get_amount() const { return amount; }
  [[nodiscard]] CurrencyCode get_currency() const { return currency; }
  [[nodiscard]] std::time_t get_timestamp() const { return timestamp; }
  [[nodiscard]] std::string to_string() const;
};

#endif