#ifndef OPERATOR_H
#define OPERATOR_H

class Operator
{
public:
    virtual double execute(double left, double right) = 0;
    virtual int priority() = 0;
    virtual ~Operator() = default;
    virtual Operator* clone() = 0;
};

#endif // OPERATOR_H
