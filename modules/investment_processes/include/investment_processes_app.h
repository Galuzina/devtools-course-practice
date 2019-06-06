// Copyright 2019 Galuzina Anna

#ifndef MODULES_INVESTMENT_PROCESSES_INCLUDE_INVESTMENT_PROCESSES_APP_H_
#define MODULES_INVESTMENT_PROCESSES_INCLUDE_INVESTMENT_PROCESSES_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char *appName, const char *message = "");
    bool ValidateNumberOfArguments(int argc, const char **argv);

    std::string message_;
};
#endif  // MODULES_INVESTMENT_PROCESSES_INCLUDE_INVESTMENT_PROCESSES_APP_H_
