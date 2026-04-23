#include "transaction.h"
#include <ctime>
#include <iomanip>
#include <sstream>

Transaction::Transaction(std::string_view from, std::string_view to,
                         double amount, CurrencyCode currency)
    : from_id(from), to_id(to), amount(amount), currency(currency),
      timestamp(std::time(nullptr)) {}

std::string Transaction::to_string() const {
  std::tm *local_time = std::localtime(&timestamp);
  std::ostringstream oss;
  oss << "[" << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << "] "
      << from_id << " -> " << to_id << ": " << std::fixed
      << std::setprecision(2) << amount << " " << ::to_string(currency);
  return oss.str();
}