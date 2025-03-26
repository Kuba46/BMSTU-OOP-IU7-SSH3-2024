#include "logic/include/commands/operatorcommand.h"
#include "logic/include/calculator.h"

OperatorCommand::OperatorCommand(Operator* op)
{
    this->op = op;
}

OperatorCommand::OperatorCommand(const OperatorCommand& command)
{
    this->op = command.op->clone();
}

OperatorCommand::~OperatorCommand()
{
    delete op;
}

void OperatorCommand::execute(Calculator& calculator)
{
    calculator.calculate(this->op);
}
