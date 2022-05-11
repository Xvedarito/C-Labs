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

int main(int argc, char* argv[])
{
    double x, y, f = 0;
    int cc;
    printf("enter variable z \n if z<1: x=z^3+0.2 \n if z>=1: x+z+log(x)\n z= ");
    int z = InputData();
    //scanf_s("%lf", &z);
        if (z < 1)
        {
            printf("Z<1 then x=z^3+0.2 \n");
            x = (z * z * z) + 0.2;
        }
        else 
        {
            printf("Z>=1 then x=z+log(z)");
            x = z + log(z);
        }
    /*else {
        printf("Not an integer");
        fflush(stdin);
        cin >> z;
    }*/
    printf("Choose wanted case. Enter (1 for F(x)=2*x) (2 for F(x)=x^2) (3 F(x)=x/3) \n cc= ");
    scanf_s("%d", &cc);
    switch (cc)
    {
    case 1:
        f = 2 * x; printf("cc=1\n f(x)=x*2"); break;
    case 2:
        f = x * x; printf("cc=2 \n f(x)=x^2"); break;
    case 3:
        f = x / 3; printf("cc=3 \n f(x)=x/3"); break;
    default: printf("Error! Invalid scenario");_getch();return 0;
    }
    y = 2 * pow(cos(pow(x, 2)), 3) + pow(sin(pow(x, 2)), 2) - f;
    printf("2*cos^3(x^2)+sin^2(x^2)-f(x)= %lf \n", y);
    puts("Press any key ...");
    _getch();
    return 0;
}