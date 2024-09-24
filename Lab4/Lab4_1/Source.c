#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "RUS");

	char c = "!";
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;

	printf("c=%c; i=%d; f=%f; d=%e\n", c, i, f, d);

	puts("Введите символ:");
	scanf_s("%c", &c);
	puts("Введите целое число:");
	scanf_s("%d", &i);
	puts("Введите вещественное число:");
	scanf_s("%f", &f);
	puts("Введите вещественное число в экспоненциальной форме:");
	scanf_s("%le", &d);

	printf("%c; %d; %f; %lf\n\n", c, i, f, d);

	puts("Задача 1а:");
	printf("Целая часть: %d; дробная часть: %f\n\n", (int)f, f - (int)f);

	puts("Задача 1б:");
	printf("Шестнадцатеричный код: %x; десятичный код: %d\n\n", c, c);

	puts("Задача 1в:");
	printf("1 / %d равно %.2f\n", i, 1. / i);
}