#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

enum currency_type: unsigned int {
    KENYAN = 0,
    UGANDAN,
    TANZANIAN,
    MAX_VALUE
};

enum currency_error: unsigned int {
    OK = 0,
    ERROR
};


class Currency {
    public:
    Currency();
    ~Currency();

    currency_error supportedCurrency(std::string all_str[]);
    currency_error setCurrent(currency_type curr);
    currency_error getCurrent(currency_type &curr);
    currency_error getCurrentStr(std::string &currency_str);
    currency_error getCurrentShortStr(std::string &currency_str);

    static Currency* get_default_instance();

    private:
    currency_type _active_currency = currency_type::KENYAN;
    std::string _curr_unit[10];
    std::string _curr_name[10];

    const char* currency_short_str[MAX_VALUE] = {
    "KSh/L",
    "UGX/L",
    "TZX/L"
};

const char* currency_long_str[MAX_VALUE] = {
    "Kenyan Shilling",
    "Ugandan Shilling",
    "Tanzanian Shilling"
};
};

#endif // CURRENCY_H