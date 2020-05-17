#pragma once
/**
* Опишите интерфейс IShape с методом double Area() и классы Square, Rectangle, Triangle, Circle,
* реализующие этот интерфейс.
* Обратите внимание на правильную инициализацию и деинициализацию ресурсов.
**/
#ifndef SHAPES_H
#define SHAPES_H

#include <vector>

//Сообственно сам интерфейс.
class IShape
{
public:
	virtual double Area() = 0;
	
	virtual ~IShape() {};
};


/** 
 * Дочерний класс Square
 * Имеет два конструктора, первый без параметров, тогда квадрат инициализируется нулевым размером,
 * и второй, в качестве параметра принимающий размер.
 * Деструктор в подобном классе не нужен, но наглядности ради будет, пусть зануляет параметры фигуры.
 **/


class Square : public IShape
{
private:
	double size;
public:
	double Area();
	void setSize(double sz);
	Square();
	Square(double sz);
	~Square();
};
			   
class Rectangle: public IShape
{
private:
    double width, 
		   height;
public:
    double Area();
    void setWidth(double w);
	void setHeight(double h);
    Rectangle();
    Rectangle(double w,double h);
    ~Rectangle();
};

class Triangle : public IShape
{
private:
	double *sides = nullptr;
public:
	double Area();
	Triangle(double s1,double s2,double s3);
	~Triangle();
};

class Circle : public IShape
{
private:
	double radius;
public:
	double Area();
	Circle(double r);
};

#endif


