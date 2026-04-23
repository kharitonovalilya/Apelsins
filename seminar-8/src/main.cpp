#include <chrono>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <variant>

#include "bankaccount.h"
#include "checkingaccount.h"
#include "currency.h"
#include "exceptions.h"
#include "savingsaccount.h"
#include "transaction.h"
#include "transfer_utils.h"

int main() {
  std::unordered_map<CurrencyCode, double> rates = {{CurrencyCode::USD, 1.0},
                                                    {CurrencyCode::EUR, 0.85},
                                                    {CurrencyCode::RUB, 75.0},
                                                    {CurrencyCode::GBP, 0.8}};
  CurrencyConverter converter(rates);

  SavingsAccount alice("Alice", 1000.0);
  CheckingAccount bob("Bob", 500.0, 200.0);
  SavingsAccount charlie("Charlie", 300.0);

  auto print_balances = [&]() {
    std::cout << "Балансы:\n";
    std::cout << "Alice: " << alice.get_balance() << " USD\n";
    std::cout << "Bob:   " << bob.get_balance() << " USD\n";
    std::cout << "Charlie: " << charlie.get_balance() << " USD\n\n";
  };

  std::cout << "Начальные балансы:\n";
  print_balances();

  try {
    std::cout << "1. Перевод 100 USD от Alice к Bob:\n";
    auto tx = execute_transfer(alice, bob, 100.0, CurrencyCode::USD, converter);
    if (tx) {
      std::cout << "Успешно: " << tx->to_string() << "\n";
    }
    print_balances();
  } catch (const std::exception &e) {
    std::cout << "Ошибка: " << e.what() << "\n";
  }

  try {
    std::cout << "2. Перевод 250 USD от Bob к Charlie (первышен лимит)\n";
    auto tx =
        execute_transfer(bob, charlie, 250.0, CurrencyCode::USD, converter);
    if (tx) {
      std::cout << "Успешно: " << tx->to_string() << "\n";
    }
    print_balances();
  } catch (const TransactionLimitExceededException &e) {
    std::cout << "Перехвачено TransactionLimitExceededException: " << e.what()
              << "\n";
    print_balances();
  }

  try {
    std::cout
        << "3. Перевод 2000 USD от Alice к Charlie (недостаточно средств):\n";
    auto tx =
        execute_transfer(alice, charlie, 2000.0, CurrencyCode::USD, converter);
    if (tx) {
      std::cout << "Успешно: " << tx->to_string() << "\n";
    }
    print_balances();
  } catch (const InsufficientFundsException &e) {
    std::cout << "Перехвачено InsufficientFundsException: " << e.what() << "\n";
    print_balances();
  }

  try {
    std::cout << "4. Перевод 50 EUR от Alice к Bob:\n";
    auto tx = execute_transfer(alice, bob, 50.0, CurrencyCode::EUR, converter);
    if (tx) {
      std::cout << "Успешно: " << tx->to_string() << "\n";
    }
    print_balances();
  } catch (const std::exception &e) {
    std::cout << "Ошибка: " << e.what() << "\n";
  }

  try {
    std::cout << "5. Перевод 50 USD от Charlie к Alice:\n";
    auto tx =
        execute_transfer(charlie, alice, 50.0, CurrencyCode::USD, converter);
    if (tx) {
      std::cout << "Успешно: " << tx->to_string() << "\n";
    }
    print_balances();
  } catch (const std::exception &e) {
    std::cout << "Ошибка: " << e.what() << "\n";
  }

  std::cout << "6. Перевод -10 USD от Alice к Bob (отрицательная сумма):\n";
  auto tx_neg =
      execute_transfer(alice, bob, -10.0, CurrencyCode::USD, converter);
  if (!tx_neg) {
    std::cout << "Перевод отменён (std::nullopt)\n";
  }
  print_balances();

  std::cout << "7. Перевод 100 XYZ от Alice к Bob (неизвестная валюта):\n";
  try {
    auto tx_inv =
        execute_transfer(alice, bob, 100.0, std::string("XYZ"), converter);
  } catch (const InvalidCurrencyException &e) {
    std::cout << "Перехвачено InvalidCurrencyException: " << e.what() << "\n";
  }
  print_balances();

  std::cout << "\n=== История транзакций ===\n";
  auto print_history = [&](const BankAccount &acc, const std::string &name) {
    std::cout << name << ":\n";
    for (const auto &tx : acc.get_history()) {
      std::cout << "  " << tx.to_string() << "\n";
    }
    std::cout << "\n";
  };
  print_history(alice, "Alice");
  print_history(bob, "Bob");
  print_history(charlie, "Charlie");

  return 0;
}