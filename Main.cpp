#include "Figures.h"
#include <iostream>

using namespace std;

int main() {
    Triangle t(1, 1, 1);
    Rectangle r(1, 2);
    Circle c(3);

    cout << "Triangle area:\t" << t.CalcArea() << "\tTriangle perimeter:\t" << t.CalcPerimeter()
        << "\nRectangle area:\t" << r.CalcArea() << "\t\tRectangle perimeter:\t" << r.CalcPerimeter()
        << "\nCircle area:\t" << c.CalcArea() << "\t\tCircle perimeter:\t" << c.CalcPerimeter()
        << endl;
    return 0;
}