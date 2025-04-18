#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <clocale>

using namespace std;

void analyze_for_loops(const string& code) {
    setlocale(LC_ALL, "Russian");

    regex for_loop_regex(
        R"(for\s*\(\s*([^;]*;)\s*([^;]*;)\s*([^)]*)\s*\)\s*(\{?)\s*([^\}]*)\s*(\}?))",
        regex_constants::ECMAScript | regex_constants::icase
    );

    sregex_iterator next(code.begin(), code.end(), for_loop_regex);
    sregex_iterator end;
    int counter = 0;

    cout << "������ ������ for � ���� C++:\n";
    cout << "========================================\n";

    while (next != end) {
        smatch match = *next;
        cout << "\n������ ���� for �����: " << ++counter << ":\n";
        cout << "������ ����������:\n " << match.str(0) << "\n";
        cout << "1. �������������: " << match.str(1) << "\n";
        cout << "2. �������: " << match.str(2) << "\n";
        cout << "3. ���������: " << match.str(3) << "\n";
        cout << "4. ���� �����: " << match.str(5) << "\n";

        if (!match.str(4).empty() && !match.str(6).empty()) {
            cout << "5. ���� � �������� �������\n";
        }
        else {
            cout << "5. ������������ ����\n";
        }

        next++;
    }

    if (counter == 0) {
        cout << "����� for �� ����������.\n";
    }
    else {
        cout << "\n����� ������� ������ for: " << counter << "\n";
    }
}

int main() {
    string code = R"(
        #include <iostream>
        
        int main() {
            for(int i = 0; i < 10; i++) {
                cout << i << endl;
            }
            
            for(int j = 0; j < 5; j++) cout << j << "2";
            
            int k = 0;
            for(; k < 3; ) {
                cout << k++;
            }
        }
    )";

    analyze_for_loops(code);

    return 0;
}