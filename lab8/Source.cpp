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
        cout << "Память успешно выделена (" << size << " элементов)" << endl;
        delete[] hugeArray;
    }
    catch (const bad_alloc& e) {
        throw MemoryException("Ошибка выделения памяти: запрошено слишком много элементов (" + to_string(size) + "). Системная ошибка: " + e.what());
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    //размеры для тестирования
    const size_t reasonableSize = 1000000;   
    const size_t hugeSize = 1000000000000;   

    cout << "Демонстрация обработки исключений при выделении памяти:\n";
    try {
        cout << "\nПопытка 1: выделение разумного размера памяти...\n";
        allocateHugeMemory(reasonableSize);
        cout << "Операция завершена успешно.\n";
    }
    catch (const MemoryException& e) {
        cerr << "Поймано исключение: " << e.what() << endl;
    }
    try {
        cout << "\nПопытка 2: выделение огромного блока памяти...\n";
        allocateHugeMemory(hugeSize);
        cout << "Операция завершена успешно.\n";
    }
    catch (const MemoryException& e) {
        cerr << "Поймано исключение: " << e.what() << endl;
    }
    try {
        cout << "\nПопытка 3: ещё одна попытка выделить огромный блок...\n";
        allocateHugeMemory(hugeSize);
    }
    catch (const exception& e) { 
        cerr << "Поймано стандартное исключение: " << e.what() << endl;
    }

    return 0;
}