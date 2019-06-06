// Copyright 2019 Galuzina Anna

#include "../include/investment_processes_app.h"
#include "../include/investment_processes.h"

#include <string>
#include <sstream>
#include <stdexcept>

double parseDouble(const std::string &arg);
int parseInt(const std::string &arg);

Application::Application() : message_("") {}

void Application::Help(const char *appName, const char *message) {
    message_ = std::string(message) +
        "This is a investment processes application. \n\n" +
        "Arguments should be provided in the following format: \n" +

        " $ " + appName + " <amount> <period> <year interest> \n\n" +
        "Where \n     <amout> is the amount of money required\n" +
            "        to purchase an apartment \n" +
        "    <period> is the period on which the mortgage is taken \n" +
        "    <year interest> is interest on which a mortgage is taken \n";
}

std::string Application::operator()(int argc, const char** argv) {
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }

    double amount;
    int period;
    double year_interest;

    try {
        amount = parseDouble(argv[1]);
        period = parseInt(argv[2]);
        year_interest = parseDouble(argv[3]);
    } catch (std::invalid_argument &e) {
        return e.what();
    }

    CalculatorResult calculator_result;
    try {
        calculator_result = Investment_processes::Calculate(amount,
                                            period, year_interest);
    } catch (std::invalid_argument &e) {
        return e.what();
    }

    std::ostringstream stream;
    stream << "Net income : " << calculator_result.net_income <<
        "\nRate of return : " << calculator_result.rate_of_return <<
        "\nPayback period : " << calculator_result.payback_period;

    message_ = stream.str();
    return message_;
}

bool Application::ValidateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 4) {
        Help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const std::string &arg) {
    char *end;
    double value = strtod(arg.c_str(), &end);

    if (end[0]) {
        throw std::invalid_argument("Wrong number format!");
    }

    return value;
}

int parseInt(const std::string &arg) {
    char *end;
    int value = static_cast<int>(strtol(arg.c_str(), &end, 10));

    if (end[0]) {
        throw std::invalid_argument("Wrong number format!");
    }

    return value;
}
