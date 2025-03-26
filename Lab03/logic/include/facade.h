#ifndef FACADE_H
#define FACADE_H

#include <string>
#include <vector>

#include "logic/include/commands/command.hpp"
#include "logic/include/calculator.h"

using str = std::string;

class Facade
{
public:
    ~Facade();

    void setExpression(const str& expression);
    str getExpression();
    void calculate();
    void run();
    bool isCommands();
    void next();
    void stop();

private:
    std::vector<Command<Calculator>*> commands;
    size_t currentCommand;
    Calculator* commandCalculator = 0;

    str expression;
    bool needToCache = false;

    void freeCommands();
    double calculateCurrentExpression();
};

#endif // FACADE_H
