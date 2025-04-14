#include "Parallelogram.h"

Parallelogram::Parallelogram(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
    : Trapezoid(x1, y1, x2, y2, x3, y3, x4, y4) {
}

bool Parallelogram::isValid() const {
    if (!Trapezoid::isValid()) return false;

    double dx1 = x2 - x1, dy1 = y2 - y1;
    double dx2 = x3 - x2, dy2 = y3 - y2;
    double dx3 = x4 - x3, dy3 = y4 - y3;
    double dx4 = x1 - x4, dy4 = y1 - y4;

    bool parallel1 = fabs(dx1 * dy3 - dy1 * dx3) < 1e-6;
    bool parallel2 = fabs(dx2 * dy4 - dy2 * dx4) < 1e-6;

    double len1 = sqrt(dx1 * dx1 + dy1 * dy1);
    double len3 = sqrt(dx3 * dx3 + dy3 * dy3);
    double len2 = sqrt(dx2 * dx2 + dy2 * dy2);
    double len4 = sqrt(dx4 * dx4 + dy4 * dy4);

    return parallel1 && parallel2 && fabs(len1 - len3) < 1e-6 && fabs(len2 - len4) < 1e-6;
}

double Parallelogram::area() const {
    double dx4 = x1 - x4, dy4 = y1 - y4;
    double len4 = sqrt(dx4 * dx4 + dy4 * dy4);
    double res = len4 * fabs(y2 - y4);
    return res;
}

void Parallelogram::printInfo() const {
    setlocale(LC_ALL, "Russian");
    cout << "Параллелограмм с вершинами: (" << x1 << "," << y1 << "), "
        << "(" << x2 << "," << y2 << "), (" << x3 << "," << y3 << "), "
        << "(" << x4 << "," << y4 << ")\n";
    cout << "Периметр: " << perimeter() << "\n";
    cout << "Площадь: " << area() << "\n";
}