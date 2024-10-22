#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int p = 3;
	float x = 4.1, y, a, b;
	a = sqrt(p * x);
	b = p * pow(x, 2) + sqrt(a);
	y = pow(log(pow(b, 2)), 3) + a * x;
	printf("y=%.1f\n", y);

	//3

	int A = (int)a, B = (int)b, C = (int)y;
	puts("Условие выполнено (1 - да, 0 - нет)");
	printf("A = %d, B = %d, C = %d\na) %d\n", A, B, C, A % 2 + B % 2 == 1);
	printf("б) %d", A % 3 == 0 && B % 3 == 0 && C % 3 == 0);
}