#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InsufficientFundsException : public std::runtime_error {
public:
  explicit InsufficientFundsException(
      const std::string &msg = "Insufficient funds")
      : std::runtime_error(msg) {}
};
class InvalidCurrencyException : public std::runtime_error {
public:
  explicit InvalidCurrencyException(const std::string &msg = "Invalid currency")
      : std::runtime_error(msg) {}
};
class TransactionLimitExceededException : public std::runtime_error {
public:
  explicit TransactionLimitExceededException(
      const std::string &msg = "Daily transaction limit exceeded")
      : std::runtime_error(msg) {}
};
#endif