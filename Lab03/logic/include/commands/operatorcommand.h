#ifndef OPERATORCOMMAND_H
#define OPERATORCOMMAND_H

#include "logic/include/commands/command.hpp"
#include "logic/include/operators/operator.h"

class Calculator;

class OperatorCommand : public Command<Calculator>
{
private:
    Operator* op;
public:
    OperatorCommand(Operator* op);
    OperatorCommand(const OperatorCommand& command);
    ~OperatorCommand();

    void execute(Calculator& calculator);
};

#endif // OPERATORCOMMAND_H
