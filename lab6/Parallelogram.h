#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Trapezoid.h"

class Parallelogram : public Trapezoid {
public:
    Parallelogram(double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);

    bool isValid() const override;
    double area() const override;
    void printInfo() const override;
};

#endif