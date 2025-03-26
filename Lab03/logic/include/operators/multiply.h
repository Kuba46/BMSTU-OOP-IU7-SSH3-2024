#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "logic/include/operators/operator.h"

class Multiply : public Operator {
public:
    double execute(double left, double right) override;
    int priority() override;
    Operator* clone() override;
};

#endif // MULTIPLY_H
