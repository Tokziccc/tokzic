#include <iostream>
#include <locale>
#include "Quadrilateral.h"
#include "Trapezoid.h"
#include "Parallelogram.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Quadrilateral quad(0, 0, 2, 2, 3, 2, 1, 2);
    if (quad.isValid()) {
        quad.printInfo();
    }
    else {
        cout << "������������ ���������������\n";
    }
    cout << "\n";

    Trapezoid trap(0, 0, 4, 2, 5, 2, 8, 0);
    if (trap.isValid()) {
        trap.printInfo();
    }
    else {
        cout << "������������ ��������\n";
    }
    cout << "\n";

    Parallelogram par(0, 0, 2, 2, 4, 2, 2, 0);
    if (par.isValid()) {
        par.printInfo();
    }
    else {
        cout << "������������ ��������������\n";
    }

    return 0;
}