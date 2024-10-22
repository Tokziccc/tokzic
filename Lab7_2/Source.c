#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    float x, y, result;
    char c;

    setlocale(LC_ALL, "RUS");
    
    puts("Введите нужную операцию (в таком формате: 5 + 3): ");
    scanf("%f %c %f", &x, &c, &y);

    
    switch (c) {
    case '+':
        result = x + y;
        printf("=%f\n", result);
        break;
    case '-':
        result = x - y;
        printf("=%f\n", result);
        break;
    case '*':
        result = x * y;
        printf("=%f\n", result);
        break;
    case '/':
        if (y != 0) 
        {
            result = x / y;
            printf("=%f\n", result);
        }
        else 
        {
            printf("Деление на 0 невозможно.\n");
        }
        break;
    case '^':
        result = pow(x, y);
        printf("=%f\n", result);
        break;
    default:
        printf("Неизвестный символ\n");
        break;
    }

    return 0;
}