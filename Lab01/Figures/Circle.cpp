#include "../Figures/Circle.h"

Circle::Circle(std::string n, Point center, double radius) : centerCoordinates(center), radius(radius)
{
    if (radius <= 0)
    {
        throw DenegradeRadiusException(typeid(*this).name());
    }
    if (!(center.getX()) || !(center.getY()))
    {
        throw DenegradeCenterException(typeid(*this).name());
    }
    nameOfFigure = std::move(n);
}

double Circle::getPerimeter()
{
    return 2 * M_PI * radius;
}

void Circle::printInfo()
{
    std::cout << "Name: " << nameOfFigure << std::endl;
    std::cout << "Type: Circle\n";
    std::cout << "Center: [" << centerCoordinates.getX() << ", " << centerCoordinates.getY() << "]" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Perimeter: " << this->getPerimeter() << std::endl;
}

void Circle::printPerimeter()
{
    std::cout << "Name: " << nameOfFigure << std::endl;
    std::cout << "Type: Circle" << std::endl;
    std::cout << "Perimeter: " << this->getPerimeter() << std::endl;
}
