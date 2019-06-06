// Copyright 2019 Egorov Vladi

#include <gtest/gtest.h>

#include "include/investment_processes.h"

TEST(Egorov_Vladi_Investment_processes, Throws_If_Amount_Less_Than_Zero) {
    // Arrange
    double amount = -1000.0;
    int period = 240;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}

TEST(Egorov_Vladi_Investment_processes, Throws_If_Amount_Is_Equal_To_Zero) {
    // Arrange
    double amount = 0;
    int period = 240;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}

TEST(Egorov_Vladi_Investment_processes,
    Throws_If_Period_Less_Than_Zero) {
    // Arrange
    double amount = 1000000.0;
    int period = -240;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}

TEST(Egorov_Vladi_Investment_processes,
    Throws_If_Period_Is_Equal_To_Zero) {
    // Arrange
    double amount = 1000000.0;
    int period = 0;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}

TEST(Egorov_Vladi_Investment_processes,
    Throws_If_Period_More_Than_Six_Hundred) {
    // Arrange
    double amount = 1000000.0;
    int period = 601;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}

TEST(Egorov_Vladi_Investment_processes, Throws_If_Interest_Less_Than_Zero) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double year_interest = -10;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}

TEST(Egorov_Vladi_Investment_processes, Throws_If_Interest_Is_Equal_To_Zero) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double year_interest = 0;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}

TEST(Egorov_Vladi_Investment_processes,
    Throws_If_Interest_More_Than_Thirty) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double year_interest = 35;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, Throws_If_Interest_Is_Very_Low) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double year_interest = 1e-20;

    // Act & Assert
    ASSERT_ANY_THROW(Investment_processes::Calculate(amount,
        period, year_interest));
}
TEST(Egorov_Vladi_Investment_processes, Can_Get_Net_Income) {
  // Arrange
  double amount = 3000000.0;
  int period = 240;
  double year_interest = 12;
  double right_net_income = 33032.58;
  double error = 0.02;
  // Act
  CalculatorResult result = Investment_processes::Calculate(amount,
  period, year_interest);
  // Assert
  EXPECT_NEAR(right_net_income, result.net_income, error);
}
TEST(Egorov_Vladi_Investment_processes, Can_Get_Payback_Period) {
  // Arrange
  double amount = 2500000.0;
  int period = 300;
  double year_interest = 11;
  double right_payback_period = 7350848.07;
  double error = 0.02;
  // Act
  CalculatorResult result = Investment_processes::Calculate(amount,
  period, year_interest);
  // Assert
  EXPECT_NEAR(right_payback_period, result.payback_period, error);
}

TEST(Egorov_Vladi_Investment_processes, Can_Get_Rate_Of_Return) {
  // Arrange
  double amount = 4300000.0;
  int period = 120;
  double year_interest = 15;
  double right_rate_of_return = 4024883.78;
  double error = 0.02;
  // Act
  CalculatorResult result = Investment_processes::Calculate(amount,
  period, year_interest);
  // Assert
  EXPECT_NEAR(right_rate_of_return, result.rate_of_return, error);
}

