#include "../Figures/Rectangle.h"

Rectangle::Rectangle(std::string n, Point TL, Point BR) : topLeft(TL), bottomRight(BR)
{
    if (BR.getX() <= TL.getX())
    {
        throw RightIsDenegradeException(typeid(*this).name());
    }
    else if (BR.getY() >= TL.getY())
    {
        throw LeftIsDenegradeException(typeid(*this).name());
    }
    nameOfFigure = std::move(n);
}

double Rectangle::getPerimeter()
{
    return 2 * (fabs(topLeft.getX() - bottomRight.getX()) + fabs(topLeft.getY() - bottomRight.getY()));
}

void Rectangle::printInfo()
{
    std::cout << "Name: " << nameOfFigure << std::endl;
    std::cout << "Type: Rectangle" << std::endl;
    std::cout << "Lower left corner coordinate: [" << topLeft.getX() << "," << topLeft.getY() << "]" << std::endl;
    std::cout << "Upper right corner coordinate: [" << bottomRight.getX() << "," << bottomRight.getY() << "]" << std::endl;
}

void Rectangle::printPerimeter()
{
    std::cout << "Name: " << nameOfFigure << std::endl;
    std::cout << "Type: Rectangle" << std::endl;
    std::cout << "Perimeter: " << this->getPerimeter() << std::endl;
}
