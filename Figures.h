#ifndef FIGURES_H
#define FIGURES_H

const double PI = 3.14159;

class Figure {
public:
    virtual double CalcArea() = 0;
    virtual double CalcPerimeter() = 0;
};


class Circle : public Figure {
    double r;
public:
    Circle(double);
    virtual double CalcArea();
    virtual double CalcPerimeter();
};

class Rectangle : public Figure {
    double a, b;
public:
    Rectangle(double, double);
    virtual double CalcArea();
    virtual double CalcPerimeter();
};

class Triangle : public Figure {
    double a, b, c;
public:
    Triangle(double, double, double);
    virtual double CalcArea();
    virtual double CalcPerimeter();
};


#endif