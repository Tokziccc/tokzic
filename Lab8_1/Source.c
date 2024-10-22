#include <stdio.h>
#include <math.h>
#include <locale.h>
#define K 1024
int main()
{
	setlocale(LC_ALL, "RUS");

	int n, m, s = 0, g = 2;
	float res, step;

	puts("¬ведите n и m(больше n) через пробел: ");
	scanf_s("%d %d", &n, &m);
	for (int i = m, k = 1; i >= n; i--)
	{
		s += i;

		printf("выполнено %d раз\n", k++);
	}
	printf("результат: %d\n\n", s);

	//1a

	for (n, m; n <= m; n++)
	{
		step = pow(2, n);
		printf("%2d ^%2d=%8.0f\n", g, n, step);
		res = pow(g, n) / K;
		printf("–езультат: %.1fK\n\n", res);
	}
}