#pragma once
#include <stdexcept>
#include <tuple>

class Transaction {
private:
  int day;
  int month;
  double amount;

public:
  Transaction();
  Transaction(int dayValue, int monthValue, double amountValue);
  int getDay() const;
  int getMonth() const;
  double getAmount() const;
  void setDay(int newDay);
  void setMonth(int newMonth);
  void setAmount(double newAmount);
  auto asTuple() const { return std::tie(month, day, amount); }
};