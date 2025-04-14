#include "Trapezoid.h"

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
    : Quadrilateral(x1, y1, x2, y2, x3, y3, x4, y4) {
}

bool Trapezoid::isValid() const {
    if (!Quadrilateral::isValid()) return false;

    double side1 = (y2 - y1) / (x2 - x1);
    double side2 = (y3 - y2) / (x3 - x2);
    double side3 = (y4 - y3) / (x4 - x3);
    double side4 = (y1 - y4) / (x1 - x4);

    return (fabs(side1 - side3) < 1e-6) || (fabs(side2 - side4) < 1e-6);
}

double Trapezoid::area() const {  
    double a = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double b = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
    double h = fabs(y2 - y4);
    double res = 0.5 * (a + b) * h;
    return res;
}

void Trapezoid::printInfo() const {
    setlocale(LC_ALL, "Russian");
    cout << "Трапеция с вершинами: (" << x1 << "," << y1 << "), "
        << "(" << x2 << "," << y2 << "), (" << x3 << "," << y3 << "), "
        << "(" << x4 << "," << y4 << ")\n";
    cout << "Периметр: " << perimeter() << "\n";
    cout << "Площадь: " << area() << "\n";
}