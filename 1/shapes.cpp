#include "shapes.h"
#include <cmath>

//реализация класса Square

Square::Square()
{
	size = 0;
}

Square::Square(double sz)
{
	size = sz;
}

Square::~Square()
{
	size = 0;
}

double Square::Area()
{
	return size*size;
}

void Square::setSize(double sz)
{
	size = sz;
}

//Реализация класса Rectangle

Rectangle::Rectangle()
{
	width = 0;
	height = 0;
}

Rectangle::Rectangle(double w, double h)
{
	width = w;
	height = h;
}

Rectangle::~Rectangle()
{
	width = 0;
	height = 0;
}

void Rectangle::setWidth(double w)
{
	width = w;
}
void Rectangle::setHeight(double h)
{
	height = h;
}

double Rectangle::Area()
{
	return height * width;
}

//Реализация класса Triangle

double Triangle::Area()
{
	if (sides ==  nullptr)
		return -1;
	
	double p = (sides[0]+sides[1]+sides[2])/2.0;
	return std::sqrt(p*(p-sides[0])*(p-sides[1])*(p-sides[2]));
}

//	посчитаем по формуле герона
Triangle::Triangle(double s1,double s2, double s3)
{	
	sides = new double[3];
	if (!(s1 > 0 && s2 > 0 && s3 > 0))
		throw "Всё сломалось! Ну какой треугольник с нулевыми или отрицательными сторонами";
	sides[0] = s1;
	sides[1] = s2;
	sides[2] = s3;
}
Triangle::~Triangle()
{
	delete[] sides;
}

Circle::Circle(double r)
{
	radius = r;
}

double Circle::Area()
{
	return M_PI *radius*radius;
}
