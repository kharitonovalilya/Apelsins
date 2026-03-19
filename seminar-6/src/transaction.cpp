#include "transaction.h"

Transaction::Transaction() : day(1), month(1), amount(0.0) {}
Transaction::Transaction(int dayValue, int monthValue, double amountValue) {
  setMonth(monthValue);
  setDay(dayValue);
  setAmount(amountValue);
}
int Transaction::getDay() const { return day; }
int Transaction::getMonth() const { return month; }
double Transaction::getAmount() const { return amount; }
void Transaction::setDay(int newDay) { day = newDay; }
void Transaction::setMonth(int newMonth) {
  if (newMonth < 1 || newMonth > 12)
    throw std::invalid_argument("month must be an integer between 1 and 12");
  month = newMonth;
}
void Transaction::setAmount(double newAmount) {
  if (newAmount < 0)
    throw std::invalid_argument("Amount cannot be negative");
  amount = newAmount;
}