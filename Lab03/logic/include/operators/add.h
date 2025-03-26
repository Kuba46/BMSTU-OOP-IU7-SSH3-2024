#ifndef ADD_H
#define ADD_H

#include "logic/include/operators/operator.h"

class Add : public Operator
{
public:
    double execute(double left, double right) override;
    int priority() override;
    Operator* clone() override;
};

#endif // ADD_H
