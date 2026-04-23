#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

enum class CurrencyCode { USD, EUR, RUB, GBP };

std::string to_string(CurrencyCode code);

std::optional<CurrencyCode> from_string(std::string_view str);

class CurrencyConverter {
public:
  explicit CurrencyConverter(
      const std::unordered_map<CurrencyCode, double> &rates_to_usd);

  double convert(double amount, CurrencyCode from, CurrencyCode to) const;

  double to_usd(double amount, CurrencyCode from) const;
  double from_usd(double amount, CurrencyCode to) const;

private:
  std::unordered_map<CurrencyCode, double> rates_to_usd_;
};