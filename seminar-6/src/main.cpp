#include <algorithm>
#include <comparators.h>
#include <iostream>
#include <safe_vector.h>
#include <tuple>

inline bool compareTransactions(const Transaction &element1,
                                const Transaction &element2) {
  return std::tie(element1.getMonth(), element1.getDay(),
                  element1.getAmount()) <
         std::tie(element2.getMonth(), element2.getDay(), element2.getAmount());
}

void print_transactions(const SafeVector<Transaction> &vector) {
  for (size_t index = 0; index < vector.size(); index++)
    std::cout << "day: " << vector[index].getDay()
              << ", month: " << vector[index].getMonth()
              << ", amount: " << vector[index].getAmount() << std::endl;
}

void safe_add(SafeVector<Transaction> &vector, int day, int month,
              double amount) {
  try {
    vector.push_back(Transaction(day, month, amount));
  } catch (const std::invalid_argument &error) {
    std::cerr << "Ошибка валидации: " << error.what() << std::endl;
  }
}

int main() {
  SafeVector<Transaction> transactions;
  safe_add(transactions, 15, 3, 150.0);
  safe_add(transactions, 10, 13, 250.0);
  safe_add(transactions, 20, 5, -10.0);
  safe_add(transactions, 5, 2, 300.0);
  safe_add(transactions, 25, 1, 50.0);
  try {
    std::cout << "До сортировки:" << std::endl;
    print_transactions(transactions);
    std::sort(transactions.begin(), transactions.end(), compareTransactions);
    std::cout << "После сортировки:" << std::endl;
    print_transactions(transactions);
    std::cout << "Пытаемся получить элемент с индексом 1:" << std::endl;
    auto &element_index_1 = transactions.at(1);
    std::cout << element_index_1.getAmount() << std::endl;
    std::cout << "Пытаемся получить элемент с индексом 7:" << std::endl;
    auto &element_index_7 = transactions.at(7);
    std::cout << element_index_7.getAmount() << std::endl;
  } catch (const std::out_of_range &error) {
    std::cerr << "Ошибка диапазона: " << error.what() << std::endl;
  }
  return 0;
}