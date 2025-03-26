#ifndef MENUEXCEPTIONS_HPP
#define MENUEXCEPTIONS_HPP

#include <string>
#include <exception>

class WrongOptionException : public std::exception
{
public:
    WrongOptionException(std::string menufile, std::string info = "Invalid input. Please enter a number between 1 and 8.\n")
    {
        errorMessage = "Error!\n" + info + ". Handled in " + menufile;
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

class EmptyListForDeletionException : public std::exception
{
public:
    EmptyListForDeletionException(std::string menufile, std::string info = "The list of figures is empty. There is nothing to delete\n")
    {
        errorMessage = "Error!\n" + info + ". Handled in " + menufile;
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

class EmptyListForShowingException : public std::exception
{
public:
    EmptyListForShowingException(std::string menufile, std::string info = "The list of figures is empty. There is nothing to show\n")
    {
        errorMessage = "Error!\n" + info + ". Handled in " + menufile;
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

class EmptyListForSummingException : public std::exception
{
public:
    EmptyListForSummingException(std::string menufile, std::string info = "The list of figures is empty. There is nothing to do\n")
    {
        errorMessage = "Error!\n" + info + ". Handled in " + menufile;
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

class EmptyListForSortException : public std::exception
{
public:
    EmptyListForSortException(std::string menufile, std::string info = "The list of figures is empty. There is nothing to sort\n")
    {
        errorMessage = "Error!\n" + info + ". Handled in " + menufile;
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

class BadIndexForDeletionException : public std::exception
{
public:
    BadIndexForDeletionException(std::string menufile, std::string info = "This index is bad to delete anything.\n")
    {
        errorMessage = "Error!\n" + info + ". Handled in " + menufile;
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

class BadInputTypeException : public std::exception
{
public:
    BadInputTypeException(std::string menufile, std::string info = "Incorrect value type")
    {
        errorMessage = "Error!\n" + info + ". Handled in " + menufile;
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;

};

#endif // MENUEXCEPTIONS_H
