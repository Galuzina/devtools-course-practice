// Copyright 2019 Egorov Vladi

#include "include/investment_processes.h"
#include <stdexcept>
#include <cmath>

CalculatorResult Investment_processes::Calculate(double amount,
    int period, double year_interest) {
    if (amount <= 0) {
        throw std::invalid_argument("Amount was entered incorrectly");
    }
    if (period <= 0 || period > 600) {
        throw std::invalid_argument("Period was entered incorrectly");
    }
    if (year_interest <= 0 || year_interest > 30) {
        throw std::invalid_argument("Interest was entered incorrectly");
    }

    CalculatorResult result;
    double month_interest = year_interest / (100 * 12);

    if ((1 - pow(1 + month_interest, -period)) == 0) {
        throw std::invalid_argument("Interest can't be so low");
    } else {
        result.net_income = amount * month_interest /
            (1 - pow(1 + month_interest, -period));
    }
    result.payback_period = result.net_income * period;
    result.rate_of_return = result.payback_period - amount;

    return result;
}
