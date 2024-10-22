#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "RUS");

	int n;

	puts("¬ведите число выводимых символов: ");
	scanf("%d", &n);
	

	for (int start = 1; start <= n; start++) 
	{
		if (start == 1 || start == n)
		{
			putchar('+');
			putchar('!');
		}
		else
			if (start <= n / 2)
			{
				putchar('*');
				putchar('!');
			}
			else
			{
				putchar('-');
				putchar('!');
			}

	}
		
}