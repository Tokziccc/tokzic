#include<stdio.h>
#include<locale.h>
#include<math.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int x, ed, des, s;
	puts("Введите трезначное число:\n ");
	scanf_s("%d", &x);
	ed = x % 10;
	des = (x / 10) % 10;
	s = x / 100;
	if (ed == des && ed == s)
		puts("Все разряды равны.");
	else
		if (ed == des)
			puts("Число единиц и десятков равно.");
		else
			if (des == s)
				puts("Число десятков и сотен равно.");
			else
				if (ed == s)
					puts("Число единиц и сотен равно.");
				else
					puts("Нет равных разрядов.");


}