#include <stdio.h>
#include <locale.h>
#define D 2.54
#define pul 2.32166
#define mm 1.852
#define spm 1609
#define rm 1475
#define srm 7468
#define gm 7412600


int main()
{
	setlocale(LC_ALL, "RUS");

	int n, g;

	puts("¬ведите число дюймов: ");
	scanf_s("%d", &n);
	printf("%d англ. дюймов = %.2f сантиметров, а %d исп. дюймов = %.2f сантиметров\n", n, n * D, n, n * pul);

	//2a

	puts("¬ведите число миль: ");
	scanf_s("%d", &g);
	printf("%d морских миль = %.2f км;\n%d сухопутных миль = %.2f км;\n%d римских миль = %.2f км;\n%d старорусских миль = %.2f км;\n%d георгафических миль = %.2f км;\n ", g, g * mm / 1000.f,
		g, g * spm / 1000.f, g, g * rm / 1000.f, g, g * srm / 1000.f, g, g * gm / 1000.f);
}