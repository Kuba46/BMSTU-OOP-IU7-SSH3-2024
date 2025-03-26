#ifndef INPUTEXCEPTIONS_HPP
#define INPUTEXCEPTIONS_HPP

#include <string>
#include <exception>

class DenegradeRadiusException : public std::exception
{
public:
    DenegradeRadiusException(std::string shapename, std::string info = "Circle creating error!\n")
    {
        errorMessage = info + "An error has been deteced during the creation of selected shape in " + shapename + " file" + "\n";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

class DenegradeCenterException : public std::exception
{
public:
    DenegradeCenterException(std::string shapename, std::string info = "Center creating error!\n")
    {
        errorMessage = info + "An error has been deteced during the creation of selected shape in " + shapename + " file" + "\n";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

class LeftIsDenegradeException : public std::exception
{
public:
    LeftIsDenegradeException(std::string shapename, std::string info = "Left rectangle's point is denegrade!\n")
    {
        errorMessage = info + "An error has been deteced during the creation of selected shape in " + shapename + " file";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

class RightIsDenegradeException : public std::exception
{
public:
    RightIsDenegradeException(std::string shapename, std::string info = "Right rectangle's point is denegrade!\n")
    {
        errorMessage = info + "An error has been deteced during the creation of selected shape in " + shapename + " file" + "\n";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

class FirstSideIsDenegradeException : public std::exception
{
public:
    FirstSideIsDenegradeException(std::string shapename, std::string info = "Side 1 is denegrade!\n")
    {
        errorMessage = info + "An error has been deteced during the creation of selected shape in " + shapename + " file" + "\n";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

class SecondSideIsDenegradeException : public std::exception
{
public:
    SecondSideIsDenegradeException(std::string shapename, std::string info = "Side 2 is denegrade!\n")
    {
        errorMessage = info + "An error has been deteced during the creation of selected shape in " + shapename + " file" + "\n";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

class ThirdSideIsDenegradeException : public std::exception
{
public:
    ThirdSideIsDenegradeException(std::string shapename, std::string info = "Side 3 is denegrade!\n")
    {
        errorMessage = info + "An error has been deteced during the creation of selected shape in " + shapename + " file" + "\n";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

class NumberOfPolygonVerticesException : public std::exception
{
public:
    NumberOfPolygonVerticesException(std::string shapename, std::string info = "Polygon can't have less than 3 vertices!\n")
    {
        errorMessage = info + "An error has been deteced while creating a " + shapename + " shape";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

class ConvexCheck : public std::exception
{
public:
    ConvexCheck(std::string shapename, std::string info = "Polygon can't have less than 3 vertices!\n")
    {
        errorMessage = info + "An error has been deteced during the creation of selected shape in " + shapename + " file" + "\n";
    }
    virtual const char* what() const noexcept override
    {
        return errorMessage.c_str();
    }
private:
    std::string errorMessage;
};

#endif