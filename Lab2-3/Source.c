#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	printf("Дано:\n\t %3d\n\t %d\n\t_______\nОтвет:\n\t%+06.1f", 4, 433, 4./433);

}