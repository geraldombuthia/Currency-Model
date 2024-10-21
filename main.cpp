#include <iostream>
#include "currency.h"
#include <cstring>

int main() {
    Currency* current = Currency::get_default_instance();
    std::string currency;
    std::string all_curr[currency_type::MAX_VALUE];

    current->setCurrent(currency_type::TANZANIAN);
    current->getCurrentStr(currency);

    printf("The current currency is %s\n", currency.c_str());

    current->getCurrentShortStr(currency);

    printf("The current currency is %s\n", currency.c_str());

    current->supportedCurrency(all_curr);

    for(int i = 0; i < currency_type::MAX_VALUE; i++) {
        printf("current %d currency is %s\n",i, all_curr[i].c_str());
    }

    return 0;
}
