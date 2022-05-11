#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
int InputData()
{
    char maxDigits = 9;
    int buffLen = 0;
    int num = 0;
    puts("Input value: ");
    while (buffLen < maxDigits) {
        char currChar = _getch();
        if (currChar == 13) {
            break;
        }
        if ((currChar >= '0' && currChar <= '9') || (currChar == '-' && buffLen == 0)) {
            putchar(currChar);
            num = num * 10 + (currChar - '0');
            buffLen++;
        }
    }
    putchar('\n');
    return num;
}
int main() {
    puts("input x, y, z");
    double a, b, c;
    int x = InputData();
    int y = InputData();
    int z = InputData();
    a = 2 * cos(x - M_PI / 6);
    b = a / (0.5 + (sin(y) * sin(y)));
    c = b * (1 + (z * z) / (3 - (z * z) / 5));
    printf("\n %lf\n %lf\n %lf", a, b, c);
}
/*int main(void)
{
double x, y, z, a, b, c, t;
puts("Enter please number and then click ENTER\nx,y,z = ");
if (scanf("%lf", &x)!=1)
    {
        printf("Not an integer.\n");
        return 0;
    }
if (scanf("%lf", &y)!=1)
    {
        printf("Not an integer.\n");
        return 0;
    }
if (scanf("%lf", &z)!=1)
    {
        printf("Not an integer.\n");
        return 0;
    }
a=2*cos(x-M_PI/6);
b=a/(0.5+(sin(y)*sin(y)));
c=b*(1+(z*z)/(3-(z*z)/5))));
printf ("\n %lf\n %lf\n %lf\n", a, b, c);
return 0;
}*/