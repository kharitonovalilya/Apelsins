#include "transfer_utils.h"
#include "exceptions.h"
#include <chrono>

std::optional<Transaction> execute_transfer(
    BankAccount& src,
    BankAccount& dst,
    double amount,
    const std::variant<CurrencyCode, std::string>& currency,
    const CurrencyConverter& converter)
{
    if (amount <= 0.0) {
        return std::nullopt;
    }

    CurrencyCode currency_code;
    if (std::holds_alternative<CurrencyCode>(currency)) {
        currency_code = std::get<CurrencyCode>(currency);
    } else {
        const std::string& cur_str = std::get<std::string>(currency);
        auto opt_code = from_string(cur_str);
        if (!opt_code.has_value()) {
            throw InvalidCurrencyException("Unknown currency: " + cur_str);
        }
        currency_code = opt_code.value();
    }

    double amount_usd = converter.convert(amount, currency_code, CurrencyCode::USD);

    dst.deposit(amount_usd);

    Transaction tx(
        src.get_owner_id(),
        dst.get_owner_id(),
        amount,
        currency_code,
        std::chrono::system_clock::now()
    );

    src.add_transaction(tx);
    dst.add_transaction(tx);

    return tx;
}