#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "RUS");

	int num;
	puts("Введите трехзначное число:");
	scanf_s("%d", &num);
	printf("a) Последняя цифра: %d \nб) Первая цифра: %d \nв) Сумма цифр: %d\n\n", num % 10, num / 100, num % 10 + num / 100 + (num / 10) % 10);
	printf("Число наобарот: %d%d%d\n", num % 10, num / 10 % 10, num / 100 % 10);
}