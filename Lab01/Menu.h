#ifndef MENU_H
#define MENU_H

#include "../Lab01/Figures/Figure.h"
#include "../Lab01/Figures/Circle.h"
#include "../Lab01/Figures/Rectangle.h"
#include "../Lab01/Figures/Triangle.h"

#include "../Lab01/Exceptions/InputExceptions.hpp"
#include "../Lab01/Exceptions/MenuExceptions.hpp"

#include <algorithm>
#include <map>
#include <sstream>
#include <utility>

#define ADD_SHAPE 1
#define PRINT_SHAPES 2
#define PRINT_PERIMETERS 3
#define CALC_SUM_OF_PERIMETERS 4
#define SORT_SHAPES 5
#define DELETE_BY_INDEX 6
#define DELETE_BY_PERIMETER_LOWER_THAN_USER_NUMBER 7
#define EXIT 8

#define ADD_CIRCLE 1
#define ADD_RECTANGLE 2
#define ADD_TRIANGLE 3
#define EXIT_TO_MAIN_MENU 4

#define SHUTDOWN 1

class Menu
{
private:
	int exitMenu = 0;
	using MethodPtr = void(Menu::*)();
	std::map<int, MethodPtr> mainMenuOptions;
	std::map<int, MethodPtr> figuresMenuOptions;
	std::vector<Figure*> figures;

	void show();
	void callMenu(const int methodName);
	void callFiguresMenu(const int methodName);
	void getBack();

	void addShape();
	void addTriangle();
	void addCircle();
	void addRectangle();

	Circle* getCircle();
	Triangle* getTriangle();
	Rectangle* getRectangle();

	void printListOfFigures();
	void printPerimeters();
	void printSumOfPerimeters();
	void sortByPerimeter();
	void deleteByIndex();
	void deleteByMaxPerimeter();

	static bool comparePerimeters(Figure* f1, Figure* f2);

	void stop();

	template<typename T>
	T getInputValue();

public:
	Menu();
	void run();
};

#endif