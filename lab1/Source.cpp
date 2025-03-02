#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <locale.h>

int task1();
int task2();
int task3();
int task4();

int main()
{
	setlocale(LC_ALL, "RUS");
	int v;
	puts("Выберете нужное задание(от 1 до 4): ");
	std::cin >> v;
	switch (v)
	{
	case 1:
		task1();
	case 2:
		task2();
	case 3:
		task3();
	case 4:
		task4();
	}
}

int task1()
{
	double a, b, res;
	std::cin >> a >> b;
	res = cos(pow(a, 2)) * (((pow((a + b), 3)) - pow(cos(pow(a, 2) + b), 2)) / sqrt(pow(sin(b), 2) + pow(cos(pow(M_PI - a, 3)), 2)));
	std::cout << res;
	return 0;
}

int task2()
{
	const float e = 0.001;
	double x, res = 0, res1 = 0;
	int pow = 1;
	std::cin >> x;
	for (int i = 1; i < 1000; i++)
	{
		res += sin(i * x) / 2 * pow;
		res1 += sin((i + 1) * x) / 2 * (2 * (pow * 2));
		pow *= 2;

		if (fabs((res1- res) <= e))
		{
			std::cout << res;
			break;
		}
	}
	return 0;
}

int task3()
{
	int s;
	std::cin >> s;
	switch (s) {
	case 1:
		{
			int n;
			std::cin >> n;
			for (int i = 1; n / 2; i++)
			{
				if (n % i == 0) {
					std::cout << i;
					puts("\n");
				}
			}

		}
	case 2: 
		{
			int n, y = 1;
			std::cin >> n;
			if (n % 2 == 0)
			{
				for (int i = 2; i <= n; i * 2)
					y *= i;
				
			}
			else
			{
				for (int i = 1; i <= n; i++)
					y *= i;

			}
			std::cout << y;
		}
	case 3:
	{
		int n;
		double p = 1;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				p *= (double)(i + 1) / i;
			}
			else {
				p *= (double)i / (i + 1);
			}
			std::cout << p;
		}
	}
	case 4:
	{
		int n;
		double x;
		double res = 0;
		std::cin >> n >> x;
		for (int k = 1; k <= n; k++)
			for (int m = k; m <= n; m++)
				res += (x + k) / m;
		std::cout << res;
	}
	case 5:
	{
		int i, j, n;
		float sum1, sum2;
		std::cin >> n;
		sum1 = 0;
		sum2 = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= i; j++)
				sum1 = sum1 + (1.0 / (i + 2 * j));
		sum2 = sum1;
		std::cout << sum2;
	}
	case 6:
	{
		double b, c, a;
		int n = 0;
		std::cin >> b >> c;
		for (int i = 1; i <= 10; i++) {
			std::cout << "a" << i + 2 << "= ";
			std::cin >> a;
			if (b < a && a > c) {
				n++;
			}
			b = c;
			c = a;
		}
		std::cout << n;

	}
	case 7:
	{
		int i = 1, j = 1;
		double P = 1.0;
		for (i; i <= 20; i++)
			for (j; j <= 20; j++)
				P *= 1.0 / (i + pow(j, 2));
		std::cout << P;
	}
	}
	return 0;
}

int task4()
{
	int n;
	std::cin >> n;
	if (n < 2 && n > -2)
		puts("Число попадет в заднный диапазон");
	else
		puts("Число не попадет в заднный диапазон");
	return 0;
}