#include <comparators.h>

inline bool compareTransactions(const Transaction &a, const Transaction &b) {
  return std::tie(a.month, a.day, a.amount) <
         std::tie(b.month, b.day, b.amount);
}

int main() {}