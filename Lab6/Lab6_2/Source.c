#include<stdio.h>
#include<locale.h>
#include<math.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	float x; 
	puts("¬ведите х:");
	scanf_s("%f", &x);
	printf("F(x) = %f", x > 3 ? x / (pow(x, 2) + 1) : - pow(x, 2) + 3 * x + 9);// x = 4, f(x) = 0,235294; x = 2, f(x) = 11
}