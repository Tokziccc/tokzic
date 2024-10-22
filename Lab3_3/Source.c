#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int a, b;
	char g = 'a', h = 'b';
	double mult, plus, minus;
	printf("¬ведите число a и b\n");
	scanf_s("%d %d", &a, &b);
	mult = a * b;
	plus = a + b;
	minus = a - b;
	printf("_______________________________________________________________________________\n");
	printf("| %10c * %-10c | %10c + %-10c | %10c - %-10c |\n", g, h, g, h, g, h, g, h);
	printf("_______________________________________________________________________________\n");
	printf("| %10d * %-10d | %10d + %-10d | %10d - %-10d |\n", a, b, a, b, a, b);
	printf("_______________________________________________________________________________\n");
	printf("| %12.2g\t\t  | %12.2g\t    | %12.2g\t      |\n",mult ,plus , minus);
	
}