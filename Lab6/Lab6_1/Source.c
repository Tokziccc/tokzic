#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{	
	setlocale(LC_ALL, "RUS");
	int yeas, ost;
	puts("Введите год:");
	scanf_s("%d", &yeas);
	ost = yeas % 4;
	printf("Остаток от деления %d на 4 равен: %d\n", yeas, ost);
	if ((ost == 0 && yeas % 100 != 0) || (yeas % 400 == 0))
		printf("Год %d является високосным.", yeas);
	else
		printf("Год %d не является високосным.", yeas);
		
	
}