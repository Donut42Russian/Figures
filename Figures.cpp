#include "Figures.h"
#include <math.h>


Circle::Circle(double radius = 1) : r(radius) {}

double Circle::CalcArea() {
    return PI * r * r;
}

double Circle::CalcPerimeter() {
    return 2 * PI * r;
}



Rectangle::Rectangle(double ia = 1, double ib = 1) : a(ia), b(ib) {}

double Rectangle::CalcArea() {
    return a * b;
}

double Rectangle::CalcPerimeter() {
    return (a + b) * 2;
}



Triangle::Triangle(double ia = 1, double ib = 1, double ic = 1) : a(ia), b(ib), c(ic) {}

double Triangle::CalcArea() {
    double p = CalcPerimeter() / 2;
    double S = p * (p - a) * (p - b) * (p - c);
    return sqrt(S);
}

double Triangle::CalcPerimeter() {
    return a + b + c;
}