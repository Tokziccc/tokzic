#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int  m, t, S;
	puts("Введите время в минутах: ");
	scanf_s("%d", &m);
	puts("Ввдеите кол-во столбов, которые поезд проходит за заданое время: ");
	scanf_s("%d", &t);
	puts("Введите растояние между столбами в метрах: ");
	scanf_s("%d", &S);
	float v = t * S / (float)m / 60.f;
	printf("Скорость поезда будет равна: %.3f м/с", v);
}