#include "currency.h"
#include <cctype>
#include <stdexcept>

std::string to_string(CurrencyCode code) {
  switch (code) {
  case CurrencyCode::USD:
    return "USD";
  case CurrencyCode::EUR:
    return "EUR";
  case CurrencyCode::RUB:
    return "RUB";
  case CurrencyCode::GBP:
    return "GBP";
  default:
    return "UNKNOWN";
  }
}

std::optional<CurrencyCode> from_string(std::string_view str) {
  std::string upper;
  for (char ch : str) {
    upper.push_back(std::toupper(static_cast<unsigned char>(ch)));
  }
  if (upper == "USD")
    return CurrencyCode::USD;
  if (upper == "EUR")
    return CurrencyCode::EUR;
  if (upper == "RUB")
    return CurrencyCode::RUB;
  if (upper == "GBP")
    return CurrencyCode::GBP;
  return std::nullopt;
}

CurrencyConverter::CurrencyConverter(
    const std::unordered_map<CurrencyCode, double> &rates_to_usd)
    : rates_to_usd_(rates_to_usd) {}

double CurrencyConverter::convert(double amount, CurrencyCode from,
                                  CurrencyCode to) const {
  double in_usd = to_usd(amount, from);
  return from_usd(in_usd, to);
}

double CurrencyConverter::to_usd(double amount, CurrencyCode from) const {
  auto it = rates_to_usd_.find(from);
  if (it == rates_to_usd_.end()) {
    throw std::invalid_argument("No exchange rate for currency " +
                                to_string(from));
  }
  return amount / it->second;
}

double CurrencyConverter::from_usd(double amount, CurrencyCode to) const {
  auto it = rates_to_usd_.find(to);
  if (it == rates_to_usd_.end()) {
    throw std::invalid_argument("No exchange rate for currency " +
                                to_string(to));
  }
  return amount * it->second;
}