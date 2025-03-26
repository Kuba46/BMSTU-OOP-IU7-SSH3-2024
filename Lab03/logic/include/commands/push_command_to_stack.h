#ifndef PUSHSTACKCOMMAND_H
#define PUSH_STACKCOMMAND_H

#include "logic/include/commands/command.hpp"

class Calculator;

class PushCommand : public Command<Calculator>
{
private:
    double number;
public:
    PushCommand(double number);

    void execute(Calculator& calculator) override;
};

#endif // PUSHSTACKCOMMAND_H
