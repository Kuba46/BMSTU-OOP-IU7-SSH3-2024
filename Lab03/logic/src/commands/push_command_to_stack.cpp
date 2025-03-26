#include "logic/include/commands/push_command_to_stack.h"

#include "logic/include/calculator.h"

PushCommand::PushCommand(double number)
{
    this->number = number;
}

void PushCommand::execute(Calculator& calculator)
{
    calculator.pushStack(number);
}
