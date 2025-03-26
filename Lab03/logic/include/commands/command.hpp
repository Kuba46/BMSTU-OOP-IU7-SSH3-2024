#ifndef COMMAND_HPP
#define COMMAND_HPP

template<typename T>
class Command
{
public:
    virtual ~Command() = default;

    virtual void execute(T& t) = 0;
};

#endif // COMMAND_HPP
