#include <iostream>
#include <new> 
#include <string>
#include <clocale>

using namespace std;

class MemoryException : public exception {
    string message;
public:
    MemoryException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

void allocateHugeMemory(size_t size) {
    try {

        int* hugeArray = new int[size];
        cout << "������ ������� �������� (" << size << " ���������)" << endl;
        delete[] hugeArray;
    }
    catch (const bad_alloc& e) {
        throw MemoryException("������ ��������� ������: ��������� ������� ����� ��������� (" + to_string(size) + "). ��������� ������: " + e.what());
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    //������� ��� ������������
    const size_t reasonableSize = 1000000;   
    const size_t hugeSize = 1000000000000;   

    cout << "������������ ��������� ���������� ��� ��������� ������:\n";
    try {
        cout << "\n������� 1: ��������� ��������� ������� ������...\n";
        allocateHugeMemory(reasonableSize);
        cout << "�������� ��������� �������.\n";
    }
    catch (const MemoryException& e) {
        cerr << "������� ����������: " << e.what() << endl;
    }
    try {
        cout << "\n������� 2: ��������� ��������� ����� ������...\n";
        allocateHugeMemory(hugeSize);
        cout << "�������� ��������� �������.\n";
    }
    catch (const MemoryException& e) {
        cerr << "������� ����������: " << e.what() << endl;
    }
    try {
        cout << "\n������� 3: ��� ���� ������� �������� �������� ����...\n";
        allocateHugeMemory(hugeSize);
    }
    catch (const exception& e) { 
        cerr << "������� ����������� ����������: " << e.what() << endl;
    }

    return 0;
}