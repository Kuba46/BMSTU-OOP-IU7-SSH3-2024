#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point(double x, double y);
	double getX();
	double getY();

private:
	double x;
	double y;
};

#endif