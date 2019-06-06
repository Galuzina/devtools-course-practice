// Copyright 2019 Egorov Vladi

#ifndef MODULES_INVESTMENT_PROCESSES_INCLUDE_INVESTMENT_PROCESSES_H_
#define MODULES_INVESTMENT_PROCESSES_INCLUDE_INVESTMENT_PROCESSES_H_

struct CalculatorResult {
    double net_income;
    double rate_of_return;
    double payback_period;
};

class Investment_processes {
 public:
     static CalculatorResult Calculate(double amount,
         int period, double year_interest);
};

#endif  // MODULES_INVESTMENT_PROCESSES_INCLUDE_INVESTMENT_PROCESSES_H_
