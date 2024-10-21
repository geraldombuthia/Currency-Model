#include "currency.h"


Currency::Currency() {

}

Currency::~Currency() {

}

Currency* Currency::get_default_instance() {
    static Currency instance;
    return &instance;
}

currency_error Currency::supportedCurrency(std::string all_str[]) {
    for(int i = 0; i < currency_type::MAX_VALUE; i++) {
        all_str[i] = currency_long_str[i];
    }
    return currency_error::OK;
}

currency_error Currency::setCurrent(currency_type curr) {

    if (curr >= currency_type::MAX_VALUE) return currency_error::ERROR;

    _active_currency = curr;

    return currency_error::OK;
}

currency_error Currency::getCurrent(currency_type &curr) {
    curr = _active_currency;

    return currency_error::OK;
}

currency_error Currency::getCurrentStr(std::string &currency_str) {
    currency_str = currency_long_str[_active_currency];
    return currency_error::OK;
}

currency_error Currency::getCurrentShortStr(std::string &currency_str) {
    currency_str = currency_short_str[_active_currency]; // Getting the short string for the current currency
    return currency_error::OK;
}