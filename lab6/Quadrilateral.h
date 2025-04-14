#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

class Quadrilateral {
protected:
    double x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Quadrilateral(double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);

    virtual bool isValid() const;
    virtual double perimeter() const;
    virtual double area() const;
    virtual void printInfo() const;
};

#endif