#include <iostream>
#include <cmath>
#include <locale.h>
#include <cstdlib>

using namespace std;

class Triangle {
public:
    int a, b, c;

    bool existence(int a, int b, int c) const {
        return (a + b > c) && (a + c > b) && (b + c > a) && (a > 0) && (b > 0) && (c > 0);
    }
    
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {
        if (!existence(a, b, c)) {
            cerr << "����������� � ������ ��������� �� ����������";
            exit(0);
        }
    }

    void printSides() {
        cout << "������� ������������: a = " << a << ", b = " << b << ", c = " << c << endl;
    }

    int perimeter() {
        return a + b + c;
    }

    double area() {
        double p = perimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }

    void setA(int value) { a = value; }
    void setB(int value) { b = value; }
    void setC(int value) { c = value; }

    int& operator[](int index) {
        switch (index) {
        case 0: return a;
        case 1: return b;
        case 2: return c;
        default:
            cerr << ("������ ������ ���� 0, 1 ��� 2");
        }
    }
    //����������
    Triangle& operator++() {
        ++a;
        ++b;
        ++c;
        return *this;
    }
    //�����������
    Triangle operator++(int) {
        Triangle temp = *this;
        ++(*this);
        return temp;
    }
    //����������
    Triangle& operator--() {
        --a;
        --b;
        --c;
        return *this;
    }
    //�����������
    Triangle operator--(int) {
        Triangle temp = *this;
        --(*this);
        return temp;
    }

    Triangle operator*(int scalar) {
        return Triangle(a * scalar, b * scalar, c * scalar);
    }

    operator bool() {
        return existence(a, b, c);
    }
};

int main() {

    setlocale(LC_ALL, "RUS");
    int a, b, c;
    cout << "������� ������� ������������: " << endl;
    cin >> a >> b >> c;
    Triangle t(a, b, c);
    t.printSides();
    cout << "��������: " << t.perimeter() << endl;
    cout << "�������: " << t.area() << endl;
    t[0] = 5; 
    cout << "����� ������� a: " << t.getA() << endl;
    ++t;
    t.printSides();
    t = t * 2;
    t.printSides();
    return 0;
}