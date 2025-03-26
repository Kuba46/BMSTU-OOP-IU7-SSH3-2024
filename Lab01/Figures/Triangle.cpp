#include "../Figures/Triangle.h"

Triangle::Triangle(std::string n, Point vertex1, Point vertex2, Point vertex3) : vertex1(vertex1), vertex2(vertex2), vertex3(vertex3)
{
    double side1 = (sqrt(pow((vertex1.getX() - vertex2.getX()), 2) + pow((vertex1.getY() - vertex2.getY()), 2)));
    double side2 = (sqrt(pow((vertex1.getX() - vertex3.getX()), 2) + pow((vertex1.getY() - vertex3.getY()), 2)));
    double side3 = (sqrt(pow((vertex2.getX() - vertex3.getX()), 2) + pow((vertex2.getY() - vertex3.getY()), 2)));
    if (side1 >= side2 + side3)
    {
        throw FirstSideIsDenegradeException(typeid(*this).name());
    }
    if (side2 >= side1 + side3)
    {
        throw SecondSideIsDenegradeException(typeid(*this).name());
    }
    if (side3 >= side1 + side2)
    {
        throw ThirdSideIsDenegradeException(typeid(*this).name());
    }
    nameOfFigure = std::move(n);
}

double Triangle::getPerimeter()
{
    return
        sqrt(pow(vertex2.getX() - vertex3.getX(), 2) + pow(vertex2.getY() - vertex3.getY(), 2)) +
        sqrt(pow(vertex3.getX() - vertex2.getX(), 2) + pow(vertex3.getY() - vertex2.getY(), 2)) +
        sqrt(pow(vertex1.getX() - vertex3.getX(), 2) + pow(vertex1.getY() - vertex3.getY(), 2));
}

void Triangle::printInfo()
{
    std::cout << "Name: " << nameOfFigure << std::endl;
    std::cout << "Type: Triangle" << std::endl;
    std::cout << "Vertex 1: [" << vertex1.getX() << ", " << vertex1.getY() << "]" << std::endl;
    std::cout << "Vertex 2: [" << vertex2.getX() << ", " << vertex2.getY() << "]" << std::endl;
    std::cout << "Vertex 3: [" << vertex3.getX() << ", " << vertex3.getY() << "]" << std::endl;
}

void Triangle::printPerimeter()
{
    std::cout << "Name: " << nameOfFigure << std::endl;
    std::cout << "Type: Triangle" << std::endl;
    std::cout << "Perimeter: " << this->getPerimeter() << std::endl;
}
