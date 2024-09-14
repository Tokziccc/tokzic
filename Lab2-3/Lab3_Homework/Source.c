#include<stdio.h>
#include<locale.h>
void main()
{
	//F = G ∙ (m1 ∙ m2) / R²  G = 6,672*10**-11
	setlocale(LC_ALL, "RUS");
	double m1, m2, r, F;
	float G = 6.67430e-11;
	puts("Введите массу первого тела: ");
	scanf("%lf", &m1);
	getchar();
	puts("Введите массу второго тела: ");
	scanf("%lf", &m2);
	getchar();
	puts("Введите растояние между телами: ");
	scanf("%lf", &r);
	getchar();
	F = G * (m1 * m2) / (r * r);
	printf("Сила притяжения заданых тел равна: %.3e\n", F);

}