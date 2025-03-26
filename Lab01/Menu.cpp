#include "Menu.h"

Menu::Menu()
{
    mainMenuOptions[ADD_SHAPE] = &Menu::addShape;
    mainMenuOptions[PRINT_SHAPES] = &Menu::printListOfFigures;
    mainMenuOptions[PRINT_PERIMETERS] = &Menu::printPerimeters;
    mainMenuOptions[CALC_SUM_OF_PERIMETERS] = &Menu::printSumOfPerimeters;
    mainMenuOptions[SORT_SHAPES] = &Menu::sortByPerimeter;
    mainMenuOptions[DELETE_BY_INDEX] = &Menu::deleteByIndex;
    mainMenuOptions[DELETE_BY_PERIMETER_LOWER_THAN_USER_NUMBER] = &Menu::deleteByMaxPerimeter;
    mainMenuOptions[EXIT] = &Menu::stop;

    figuresMenuOptions[ADD_CIRCLE] = &Menu::addCircle;
    figuresMenuOptions[ADD_RECTANGLE] = &Menu::addRectangle;
    figuresMenuOptions[ADD_TRIANGLE] = &Menu::addTriangle;
}

void Menu::run()
{
    exitMenu = 0;
    do
    {
        show();
        try
        {
            int choice = getInputValue<int>();
            callMenu(choice);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (exitMenu == 0);
}

void Menu::show()
{
    std::cout << "Welcome to the app where you can create figures and calculate their perimeter." << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add figure" << std::endl;
    std::cout << "2. Print list of figures with their parameters" << std::endl;
    std::cout << "3. Print list of figures with their perimeters" << std::endl;
    std::cout << "4. Print the sum of the perimeters of all figures" << std::endl;
    std::cout << "5. Sort the figures by their perimeters (from minimal to maximal)" << std::endl;
    std::cout << "6. Delete a figure from the collection by its number" << std::endl;
    std::cout << "7. Delete figures whose perimeters are larger than your number" << std::endl;
    std::cout << "8. Exit" << std::endl;
}

void Menu::addShape()
{
    std::cout << "Choose a figure you want to add:" << std::endl;
    std::cout << "1. Circle" << std::endl;
    std::cout << "2. Rectangle" << std::endl;
    std::cout << "3. Triangle" << std::endl;
    try
    {
        int choice = getInputValue<int>();
        callFiguresMenu(choice);
    }
    catch (const WrongOptionException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Shape added!" << std::endl;
}

void Menu::getBack()
{

}

void Menu::addCircle()
{
    Circle* circle = getCircle();
    figures.push_back(circle);
}

Circle* Menu::getCircle()
{
    std::string name;
    std::cout << "Enter a name for your figure:" << std::endl;
    std::cin >> name;
    std::cout << "Enter the coordinates of center:" << std::endl;
    Point centerCoordinate(getInputValue<double>(), getInputValue<double>());
    std::cout << "Enter the length of your radius" << std::endl;
    double radius = getInputValue<double>();
    return new Circle(name, centerCoordinate, radius);
}

void Menu::addRectangle()
{
    Rectangle* rectangle = getRectangle();
    figures.push_back(rectangle);
}

Rectangle* Menu::getRectangle()
{
    std::string name;
    std::cout << "Enter a name for your figure:" << std::endl;
    std::cin >> name;
    std::cout << "Enter the coordinates of upper left vertex:" << std::endl;
    Point upperLeftCornerCoord(getInputValue<double>(), getInputValue<double>());
    std::cout << "Enter the coordinates of bottom right vertex:" << std::endl;
    Point lowerRightCornerCoord(getInputValue<double>(), getInputValue<double>());
    return new Rectangle(name, upperLeftCornerCoord, lowerRightCornerCoord);
}

void Menu::addTriangle()
{
    Triangle* triangle = getTriangle();
    figures.push_back(triangle);
}

Triangle* Menu::getTriangle()
{
    std::string name;
    std::cout << "Enter a name for your figure:" << std::endl;
    std::cin >> name;
    std::cout << "Enter the coordinates coordinates of three points:" << std::endl;
    Point firstCoordinate(getInputValue<double>(), getInputValue<double>());
    Point secondCoordinate(getInputValue<double>(), getInputValue<double>());
    Point thirdCoordinate(getInputValue<double>(), getInputValue<double>());
    return new Triangle(name, firstCoordinate, secondCoordinate, thirdCoordinate);
}

void Menu::printListOfFigures()
{
    unsigned counter = 1;
    if (figures.empty())
    {
        throw EmptyListForShowingException(typeid(*this).name());
    }
    for (const auto& figure : figures)
    {
        std::cout << counter << ". ";
        figure->printInfo();
        counter++;
    }
}

void Menu::printPerimeters()
{
    unsigned counter = 1;
    if (figures.empty())
    {
        throw EmptyListForShowingException(typeid(*this).name());
    }
    for (const auto& figure : figures)
    {
        std::cout << counter << ". ";
        figure->printPerimeter();
        counter++;
    }
}

void Menu::printSumOfPerimeters()
{
    if (figures.empty())
    {
        throw EmptyListForSummingException(typeid(*this).name());
    }
    double sum = 0;
    for (const auto& figure : figures)
    {
        sum += figure->getPerimeter();
    }
    std::cout << "Sum of Perimeters: " << sum << std::endl;
}

void Menu::sortByPerimeter()
{
    if (figures.empty())
    {
        throw EmptyListForSortException(typeid(*this).name());
    }
    std::sort(figures.begin(), figures.end(), comparePerimeters);
    std::cout << "Figures have been sorted!: " << std::endl;
}

bool Menu::comparePerimeters(Figure* f1, Figure* f2)
{
    return (f1->getPerimeter() < f2->getPerimeter());
}

void Menu::deleteByIndex()
{
    if (figures.empty())
    {
        throw EmptyListForDeletionException(typeid(*this).name());
    }
    std::cout << "Enter an index of a figure you want to delete (from 0): " << std::endl;
    int index = getInputValue<int>();
    if (index < 1 || index > figures.size())
    {
        throw BadIndexForDeletionException(typeid(*this).name());
    }
    delete figures[index];
    figures.erase(figures.begin() + index);
    std::cout << "Figure has been deleted!" << std::endl;
}

void Menu::deleteByMaxPerimeter()
{
    if (figures.empty())
    {
        throw EmptyListForDeletionException(typeid(*this).name());
    }
    std::cout << "Enter a value to delete figures with larger perimeters: " << std::endl;
    double enteredValue = getInputValue<double>();
    for (unsigned i = 0; i < figures.size(); i++)
    {
        if (figures[i]->getPerimeter() > enteredValue)
        {
            delete figures[i];
            figures.erase(figures.begin() + i);
        }
    }
    std::cout << "Figures have been deleted!\n";
}

void Menu::stop()
{
    exitMenu = SHUTDOWN;
}

void Menu::callMenu(const int methodName)
{
    auto it = mainMenuOptions.find(methodName);
    if (it != mainMenuOptions.end())
    {
        (this->*(it->second))();
    }
    else
    {
        std::cerr << "Menu option not found" << std::endl;
    }
}

void Menu::callFiguresMenu(const int methodName)
{
    auto it = figuresMenuOptions.find(methodName);
    if (it != figuresMenuOptions.end())
    {
        (this->*(it->second))();
    }
    else
    {
        throw WrongOptionException(typeid(*this).name());
    }
}

template<typename T>
T Menu::getInputValue()
{
    T value;
    std::cin >> value;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw BadInputTypeException(typeid(*this).name());
    }
    return value;
}
