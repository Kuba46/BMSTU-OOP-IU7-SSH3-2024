#include "logic/include/translator.h"
#include "logic/include/operators/operatorcreator.h"

Translator::Translator(const str& input)
{
    this->input = input;
} 

str Translator::join(std::vector<str>& parts)
{
    str result = "";
    for (size_t i = 0; i < parts.size(); i++)
    {
        result += parts[i];
        if (i != parts.size() - 1)
        {
            result += ' ';
        }
    }
    return result;
}

str Translator::translate()
{
    if (this->input.length() == 0)
    {
        return "";
    }
    OperatorCreator operatorCreator;
    std::vector<str> output;
    std::vector<str> stack;
    bool makeNumber = true;
    for (size_t i = 0; i < input.length(); i++)
    {
        if ((digits.find(input[i]) != str::npos || input[i] == '-') && makeNumber)
        {
            makeNumber = false;
            output.push_back(str{input[i]});
        }
        else if (digits.find(input[i]) != str::npos)
        {
            output.rbegin()->push_back(input[i]);
        }
        else if (brackets.find(input[i]) != str::npos)
        {
            if (input[i] == '(')
            {
                stack.push_back(str{input[i]});
            }
            else
            {
                while (stack.rbegin()->at(0) != '(')
                {
                    output.push_back(*stack.rbegin());
                    stack.erase(stack.begin() + (stack.size() - 1));
                }
                stack.erase(stack.begin() + (stack.size() - 1));
            }
        }
        else
        {
            makeNumber = true;
            if (stack.empty() || stack.rbegin()->at(0) == '(')
            {
                stack.push_back(std::string{input[i]});
            }
            else if (operatorCreator.priority(input[i]) <= operatorCreator.priority(stack.rbegin()->at(0)))
            {
                output.push_back(*stack.rbegin());
                stack.erase(stack.begin() + (stack.size() - 1));
                stack.push_back(std::string{input[i]});
            }
            else
            {
                stack.push_back(std::string{input[i]});
            }
        }
    }
    for (auto iter = stack.rbegin(); iter != stack.rend(); iter++) {
        output.push_back(*iter);
    }
    return join(output);
}
