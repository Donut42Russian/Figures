#pragma once
class Figure
{
public:
    virtual double calcArea() = 0;
    virtual double calcPerimeter() = 0;
};

class Circle : public Figure
{
private:
    int r;
public:
    double calcArea();
    double calcPerimeter();
    int getR();
    void setR(int r);

    Circle(int r);
    virtual ~Circle();
};

class Triangle : public Figure
{
private:
    double a, b, c;
    int x1, y1, x2, y2, x3, y3;
public:
    enum side{ A = 1, B = 2, C = 3};
    double calcArea();
    double calcPerimeter();
    double getSide(int number);
    void getCoordinate(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3);

    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    virtual ~Triangle();
};

class Rectangle : public Figure
{
private:
    double a, b, c, d;
    int x1, y1, x2, y2, x3, y3, x4, y4;
public:
    enum side{ A = 1, B = 2, C = 3, D = 4};
    double calcArea();
    double calcPerimeter();
    double getSide(int number);
    void getCoordinate(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4);

    Rectangle(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);
    virtual ~Rectangle();
};

