#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {
}

bool Quadrilateral::isValid() const {
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) ||
        (x1 == x4 && y1 == y4) || (x2 == x3 && y2 == y3) ||
        (x2 == x4 && y2 == y4) || (x3 == x4 && y3 == y4)) {
        return false;
    }
    return true;
}

double Quadrilateral::perimeter() const {
    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    double d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
    return a + b + c + d;
}

double Quadrilateral::area() const {
    double res = 0.5 * fabs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
    return res;
}

void Quadrilateral::printInfo() const {
    setlocale(LC_ALL, "Russian");
    cout << "Четырехугольник с вершинами: (" << x1 << "," << y1 << "), "
        << "(" << x2 << "," << y2 << "), (" << x3 << "," << y3 << "), "
        << "(" << x4 << "," << y4 << ")\n";
    cout << "Периметр: " << perimeter() << "\n";
    cout << "Площадь: " << area() << "\n";
}