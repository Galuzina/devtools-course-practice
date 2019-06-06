// Copyright 2019 Galuzina Anna

#include <gtest/gtest.h>

#include <vector>
#include <cmath>
#include <string>
#include <functional>

#include "../include/investment_processes_app.h"

using ::testing::internal::RE;

class InvestmentProcessesAppTest : public ::testing::Test {
 protected:
    void Act(const std::vector<std::string> &args_) {
        std::vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(const std::string &expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
    Application app_;
    std::string output_;
};

TEST_F(InvestmentProcessesAppTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a Investment Processes application\\..*");
}

TEST_F(InvestmentProcessesAppTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = {"5.2", "1"};

    Act(args);

    Assert("This is a Investment Processes application\\..*");
}

TEST_F(InvestmentProcessesAppTest, Can_InvestmentProcesses) {
    std::vector<std::string> args = {"5.2", "3", "10"};

    Act(args);

    double month_interest = 10.0 / (100 * 12);
    double net_income = 5.2 * month_interest /
        (1 - pow(1 + month_interest, - 3));
    double payback_period = net_income * 3;
    double rate_of_return = payback_period - 5.2;

    std::ostringstream stream;
    stream << "Monthly payment : " << net_income <<
        "\nOverpayment amount : " << payback_period <<
        "\nTotal payout : " << rate_of_return;

    Assert(stream.str());
}

TEST_F(InvestmentProcessesAppTest, Throw_Exception_When_Amount_Is_Invalid) {
    std::vector<std::string> args = {"0", "3", "10"};

    Act(args);

    Assert("Amount was entered incorrectly");
}

TEST_F(InvestmentProcessesAppTest, Throw_Exception_When_Period_Is_Invalid) {
    std::vector<std::string> args = {"5.2", "0", "10"};

    Act(args);

    Assert("Period was entered incorrectly");
}

TEST_F(InvestmentProcessesAppTest, Throw_Exception_When_Interest_Is_Invalid) {
    std::vector<std::string> args = {"5.2", "3", "40"};

    Act(args);

    Assert("Interest was entered incorrectly");
}

TEST_F(InvestmentProcessesAppTest, Throw_Exception_When_Interest_Is_Low) {
    std::vector<std::string> args = {"5.2", "599", "1e-15"};

    Act(args);

    Assert("Interest can't be so low");
}

TEST_F(InvestmentProcessesAppTest, Throw_Exception_When_Can_Not_Parse_Int) {
    std::vector<std::string> args = {"5.2", "599f", "10"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(InvestmentProcessesAppTest, Throw_Exception_When_Can_Not_Parse_Double) {
    std::vector<std::string> args = {"5.2f", "599", "10.1"};

    Act(args);

    Assert("Wrong number format!");
}
