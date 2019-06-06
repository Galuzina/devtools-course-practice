// Copyright 2019 Galuzina Anna

#include <iostream>
#include <string>

#include "../include/investment_processes_app.h"

int main(int argc, const char **argv) {
    Application app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;

    return 0;
}
