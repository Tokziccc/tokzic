#include <stdio.h>

void main()
{
	int a = 11, b = 3;
	int x;
	float y;
	double z;

	x = a / b;
	y = a / b;
	z = a / b;

	printf("x: %d; y: %f; z: %f\n\n", x, y, z);

	printf("int: %d; float: %f; double: %f\n", (int)a / b, (float)a / b, (double)a / b);
}