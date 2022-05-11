#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef double (*FP)(double, int);

double func(double x, int n) {
    return (exp(x) + exp(-x)) / 2;
}

double suma(double x, int n) {
    double t, y = 1, z = 2, r, s = 1;;
    r = (x * x / 2);

    for (int k = 2; k <= n; k++)
    {
        s += r;
        t = (x * x) / ((y += 2) * (z += 2));
        r = r * t;
    }

    return s;
}

double razn(double x, int n) {
    return abs(func(x, n) - suma(x, n));
}

void out(const char* message, FP func, double from, double to, double step, int n) {
    for (double i = from; i * (step < 0 ? -1 : 1) <= to * (step < 0 ? -1 : 1); i += step) {
        printf("\nx = %5.2lf, %s%lf", i, message, func(i, n));
    }
    printf("\n");
}

int main(void)
{
    double a, b, h;
    int n, value;

    printf("Print 0 to start manual or other number to start auto \n v= ");
    scanf_s("%4d", &value);
    if (value == 0) {
        printf("You chose manual mod. \n  ");
        printf("Enter please start x: ");
        scanf_s("%lf", &a);
        printf("Enter please end x: ");
        scanf_s("%lf", &b);
        printf("Enter please step: ");
        scanf_s("%lf", &h);
        printf("Enter please n: ");
        scanf_s("%d", &n);

        if (abs(b - a) < abs(h)) {
            puts("Шаг больше, чем промежуток, будет взят только начальный x"); //лень перевести на английский
        }
        if (a == b) {
            puts("Начальный индекс равен конечному, устанавливаю конечный индекс на 1 больше начального");
            b++;
        }
        if (a > b && h > 0) {
            puts("Начальный индекс не может быть меньше конечного, меняю местами");
            swap(a, b);
        }
        if (h == 0) {
            puts("Шаг равен <=0, вычисление никогда не закончится, теперь шаг = 0.1");
            h = 0.1;
        }

        if (n <= 0) {
            puts("Количество членов в сумме не может быть меньше <= 0, использую дефолтное количество : 3 члена");
            n = 3;
        }

    }
    else {
        printf("You chose auto mod. \n  "); //можно написать ввиде рандома
        a = 0;
        b = 5;
        h = 0.1;
        n = 10;
    }

   // printf("Print 0 to output Y(x), 1 to output S(x), 2 to output |Y(x)-S(x)|, other number to output all\n v= ");
   // scanf_s("%4d", &value); //выбор желаемой функции

    printf("Output for Y(x)\n");
    out("Y(x) = ", func, a, b, h, n);
    printf("Output for S(x)");
    out("S(x) = ", suma, a, b, h, n);
    printf("Output for |Y(x)-S(x)|");
    out("|Y(x)-S(x)| = ", razn, a, b, h, n);

    return 0;
}

