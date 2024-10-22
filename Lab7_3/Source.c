#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M 12
int main()
{
	setlocale(LC_ALL, "rus");

	int n, years, m;

	puts("¬ведите число мес€цев до 60: ");
	scanf_s("%d", &n);

	m = n % M;
	years = n / M;

	switch (years)
	{
	case 1:
		printf("%d год\n", years);
		break;
	case 2:
	case 3:
	case 4:
		printf("%d года\n", years);
		break;
	case 5:
		printf("%d лет\n", years);
		break;
	default:
		puts("");
	}

	switch (m)
	{
	case 1:
		printf("%d мес€ц\n", m);
		break;
	case 2:
	case 3:
	case 4:
		printf("%d мес€ца\n", m);
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		printf("%d мес€цев\n", m);
		break;
	default:
		puts("");
	
	}
	
 }