#include <math.h>
#include <iostream>
using namespace std;

int function(int p, int x)
{
	int remainder, rez = 0;
	for (int numeral = 1; x > 0;)
	{
		remainder = x % p; // остаток от числа
		x = x / p; // само число этого разряда
		rez += remainder * numeral;
		numeral *= 10;
	}
	return rez;
}
int recursive(int p, int x, int rez)
{
	int remainder;
	if (x > 0)
	{
		remainder = x % p;
		return recursive(p, x/p, rez += remainder * 10);
		//return remainder + recursive(p, x/p) * 10;
	}
	return rez;
}

int input_data(const char* text)
{
	int x;
	cout << text;
	while (!(cin >> x) || cin.get() != '\n')
	{
		cout << "\n Wrong input, enter again";
		cin.clear();
		cin.ignore();
	}
	return x;
}

int main()
{
	int x, y, p, rez = 0;
	cout << "enter variables ";
	x = input_data("x = ");
	do {
		p = input_data("p = ");
	} while (p > 10);
	y = function(p, x);
	cout << "\n simple function = " << y << endl;
	y = recursive(p, x, rez);
	cout << "\n recursive function = " << y << endl;
}