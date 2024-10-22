#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "rus");
    int a;
    float b;
    puts("y = |lg(x)|-(x-2)^2");
    puts("¬ведите шаг: ");
    double tab;
    scanf("%lf", &tab);
    puts("¬ведите интервалы a и b\n");
    scanf("%d %f", &a, &b);
    
    

    puts("____________________\n");
    for (float x = (float)a; x <= b; x += tab) 
    {
        printf("|  %4.3g  |  %4.3g  |\n", x,(fabs(log10(x))-pow((x-2),2)));
        puts("____________________\n");
    }
}
