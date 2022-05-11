#include <iostream>
#include <conio.h>
using namespace std;

double fun(double x) {
    return x * x * x + 6 * x * x - 0.02 * exp(x) - 14;
}

double dx(double x, double epsilon) {
    return 3 * x * x + 12 * x - 0.02 * exp(x);
}

double fun2(double x) {
    return -(x + 2) * (x + 2);
}

double Method_Newton(double x1, double epsilon, int& c) {
    double x0;
    c = 0;
    do {
        x0 = x1;
        x1 = x0 - fun(x0) / dx(x0, epsilon);
        c++;
    } while (fabs(x1 - x0) > epsilon);
    return x1;
}

double Metod_Del_2(double x0, double x1, double epsilon, int& c) {
    double x2, y0, y2;
    c = 0;
    y0 = fun(x0);
    do {
        x2 = (x0 + x1) / 2;
        y2 = fun(x2);
        if (y0 * y2 > 0) {
            x0 = x2;	y0 = y2;
        }
        else x1 = x2;
        c++;
    } while (x1 - x0 > epsilon);
    return (x0 + x1) / 2;
}

double input(char, char);

int main() {
    double a, b, h, epsilon, x, x0, xn = NULL, xk = NULL;
    int nom = 0, c, d;
    char n[2];
    while (1) {
        cout << "\n\t 1 - Simple root: f(x) = x^3 + 6x^2 - 0.02e^x - 14\n\t 2 - Special root:  f(x) = -(x + 2)^2\n\t 0 - Exit   :   ";
        do {
            n[0] = _getch();
            n[1] = '\0';
        } while (!(n[0] >= '0' && n[0] <= '2'));
        cout << n[0] << endl;

        switch (n[0]) {

        case '0':
            return 0;

        case '1':
            cout << "\n Input data:" << endl;
            cout << "\n standart a = -6";
            cout << "\n standart b = 2" << endl;
            a = input('a', 'd');
            do {
                b = input('b', 'd');
            } while (b <= a);
            do {
                epsilon = input('e', 'd');
            } while (epsilon <= 0);
            h = input('h', 'd');
            while (h < epsilon) {
                cout << " Step should not be less than epsilon!" << endl;
                h = input('h', 'd');
            }

            cout << "\n Newton's Method:" << endl;
            nom = 0;
            for (x = a; x <= b; x += h) {
                if (fun(x) * fun(x + h) < 0) {
                    nom++;
                    x0 = Method_Newton(x, epsilon, c);
                    cout << nom << "-th root: " << x0 << " \tCount of iterations: " << c << "\ty(x) = " << fun(x0) << endl;
                }
            }
            if (nom == 0) cout << " No root!" << endl;

            cout << "\n Bisection method: " << endl;
            nom = 0;
            for (x = a; x <= b; x += h) {
                if (fun(x) * fun(x + h) < 0) {
                    nom++;
                    x0 = Metod_Del_2(x, x + h, epsilon, c);
                    cout << nom << "-th root: " << x0 << " \tCount of iterations: " << c << "\ty(x) = " << fun(x0) << endl;
                }
            }
            if (nom == 0) cout << " No root!" << endl;
            break;

        case '2': cout << "\n Input data:" << endl;
            a = input('a', 'd');
            do {
                b = input('b', 'd');
            } while (b <= a);
            do {
                epsilon = input('e', 'd');
            } while (epsilon <= 0);
            h = input('h', 'd');
            while (h < epsilon) {
                cout << " Step should not be less than epsilon!" << endl;
                h = input('h', 'd');
            }
            nom = 0;
            for (x = a; x <= b; x += h) {
                if (abs(fun2(x)) < epsilon) {
                    xn = x;
                    continue;
                }
                if (xn != NULL && abs(fun2(x)) >= epsilon) {
                    xk = x;
                    nom++;
                    cout << " [" << xn << ", " << xk << "]" << endl;
                    xn = NULL;
                    continue;
                }
            }
            if (nom == 0) cout << " No root!" << endl;
            break;
        }
    }
}
        

double input(char t, char mode) {
    char s[20];
    int i = 0;
    bool f = true;
    cout << t << " = ";
    while (1) {
        s[i] = _getch();
        if (i == 0 && s[0] == '-') {
            cout << s[0];
            i++;
            continue;
        };
        if (mode == 'd') {
            if (s[i] == '.' && i != 0 && s[i - 1] != '-' && f == true) {
                cout << s[i];
                s[i] = '.';
                f = false;
                i++;
                continue;
            }
        }
        if (s[i] == 8) {
            cout << '\b' << " " << '\b';
            s[i - 1] = '\0';
            --i;
            continue;
        }
        if (s[i] == 13 && s[i - 1] >= '0' && s[i - 1] <= '9') break;
        if (!(s[i] >= '0' && s[i] <= '9')) continue;
        cout << s[i];
        i++;
    }
    s[i] = '\0';
    cout << endl;
    return atof(s);
}