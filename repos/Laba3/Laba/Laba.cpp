
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double n, a, b, h, rs, s,y;
	printf(" input min A = ");
	scanf_s("%lf", &a);
	printf("max B = "); 
	scanf_s("%lf", &b);
	printf("step H = ");
	scanf_s("%lf", &h);
	printf("number of interatction N = ");
	scanf_s("%lf",&n);
	/*do {
		fflush(stdin);
	} while (false);*/
	for (double i = a; i <= b;i += h)
	{
		y = (exp(cos(i / 180 * M_PI))) * cos(sin(i / 180 * M_PI));
		s = rs = 1;
		for (double k = 1;k <= n;k++) 
		{
			rs = cos(i * k / 180 * M_PI) * rs / k;
			//printf("%8.2lf", r);
			s += rs;
		}
		printf("\n x=%6.2lf \t sum=%3lf \t y=%8.5lf \t y-sum=%8.5lf", i,s,y,s-y);
	}	
}
