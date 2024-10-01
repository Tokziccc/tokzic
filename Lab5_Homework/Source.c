#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
int main()
{
	float x = 3.251, y = 0.325;
	double z = 0.466e-4, res1, res2, res3, res4, res5, res;
	res1 = pow(y, x);
	res2 = pow(2, res1);
	res1 = pow(3, x);
	res3 = pow(res1, y);
	res5 = res3 + res2;
	res1 = atan(z);
	res2 = M_PI / 6.f;
	res3 = y * (res1 - res2);
	res1 = fabs(x);
	res2 = 1.f / (pow(y, 2) + 1);
	res4 = res3 / (res1 + res2);
	res = res5 - res4;
	printf("c = %.6f", res);



}