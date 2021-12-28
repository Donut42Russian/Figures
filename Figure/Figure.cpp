#define _USE_MATH_DEFINES
#include "Figure.h"
#include <cmath>
#include "Error.h"
//Circle

double Circle::calcArea()
{
	return M_PI * r * r;
}

double Circle::calcPerimeter()
{
	return 2 * M_PI * r;
}

int Circle::getR()
{
	return r;
}

void Circle::setR(int r)
{
    this->r = r;
}

Circle::Circle(int r)
{
	if (r > 0) this->r = r;
    else throw Error("Error creating circle");
}

Circle::~Circle()
{

}

//Triangle

double Triangle::calcArea()
{
    double p = calcPerimeter() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::calcPerimeter()
{
	return a + b + c;
}

double Triangle::getSide(int number)
{
	switch (number)
	{
	case 1:
	{
		return a;
	}
	case 2:
	{
		return b;
	}
	case 3:
	{
		return c;
	}
	default:
		break;
	}
    throw Error("Error select side");
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
	{
        this->a = a;
        this->b = b;
        this->c = c;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
	}
    else throw Error("Error creating triangle");
}

void Triangle::getCoordinate(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3)
{
    x1 = this->x1;
    y1 = this->y1;
    x2 = this->x2;
    y2 = this->y2;
    x3 = this->x3;
    y3 = this->y3;
}

Triangle::~Triangle()
{

}

//Rectangle

double Rectangle::calcArea()
{
    return (x2-x1)*(y2-y1);

}

double Rectangle::calcPerimeter()
{
    return 2*((x2-x1)+(y2-y1));
}


Rectangle::~Rectangle()
{

}

double Rectangle::getSide(int number)
{
    switch (number)
    {
    case 1:
    {
        return a;
    }
    case 2:
    {
        return b;
    }
    case 3:
    {
        return c;
    }
    case 4:
    {
        return d;
    }
    default:
        break;
    }
    throw Error("Error select side");
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    double a,b,c,d;
    a=abs(x2-x1);
    b=abs(y2-y1);
    c=a;
    d=b;
    if(a>0 && b>0)
    {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
    this->x4 = x4;
    this->y4 = y4;
    }
    else throw Error("Error creating rectangle");
}

void Rectangle::getCoordinate(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4)
{
    x1 = this->x1;
    y1 = this->y1;
    x2 = this->x2;
    y2 = this->y2;
    x3 = this->x1;
    y3 = this->y1;
    x4 = this->x2;
    y4 = this->y2;
}
