#include <iostream>
#include <conio.h>
using namespace std;

double fun(double x) {
	return x * x * x + 6 * x * x - 0.02 * exp(x);
}

typedef double (*type_f)(double, double, double);

double Gauss_method_2(double a, double b, double n) {
	double sum = 0, h, x, x1, x2, c1, c2;
	h = (b - a) / n;
	x = a;
	c1 = h / 2 * (1 - 0.5773502692);
	c2 = h / 2 * (1 + 0.5773502692);
	do {
		x1 = x + c1;
		x2 = x + c2;
		sum += fun(x1) + fun(x2);
		x += h;
	} while (x + h / 3 < b);
	return h / 2 * sum;
}

double Trapez_method(double a, double b, double n)
{
	double sum = 0, h, x;
	h = (b - a) / n;
	x = a;
	do {
		sum += (fun(x) + fun(x + h)) / 2;
		x += h;
	} while (x + h / 3 < b);
	return  sum * h;
}

int calc(double a, double b, double c, type_f method) {
	double I1, I2, diff;
	int n = 0;
	if (method == Gauss_method_2) cout << "\nGauss Method:  \t";
	else cout << "\nTrapez Method:\t";

	if (c >= 1) {
		I1 = method(a, b, c);
	}
	else {
		n = 2;
		I1 = method(a, b, n);
		do {
			n *= 2;
			I2 = method(a, b, n);
			diff = fabs(I2 - I1);
			I1 = I2;
		} while (diff > c);
	}
	cout << "Integral = " << I1 << ";\t";
	if (n != 0)	cout << "n = " << n;
	if (method == Gauss_method_2) calc(a, b, c, Trapez_method);
	return 0;
}

double input(char, char);

int main() {
	double a, b, eps, n;

	cout << " 11. f(x) = x^3 + 6x^2 - 0.02e^x, with a = -5 and b = 3, integral = 167.6" << endl;
	do {
		cout << "\n Input range:" << endl;
		a = input('a', 'd');
		do {
			b = input('b', 'd');
		} while (b < a);

		cout << "\n Input n:" << endl;
		do {
			n = input('n', 'i');
		} while (n < 1);
		cout << "\n Input eps:" << endl;
		do {
			eps = input('e', 'd');
		} while (eps <= 0 || eps >= 1);

		cout << "\n------ Splitting into n segments ------" << endl;
		calc(a, b, n, Gauss_method_2);

		cout << "\n\n--------- By accuracy eps ---------" << endl;
		calc(a, b, eps, Gauss_method_2);

		cout << "\n 1 - Continue\n Else - Exit" << endl;
	} while (_getch() == '1');
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