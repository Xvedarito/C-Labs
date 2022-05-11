// Test str.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
	char str[10] = "He1l0";
	int n = strlen(str);
	for (int i = 0;i < n;i++)
	{
		/*for (auto number : str) // тип number определяется автоматически исходя из типа элементов массива math
		{
			std::cout << number << '\t';
		}*/
		for (int dig = 0;dig < 10;dig++)
		{
			if (str[i] == dig)
			{
				printf("%d\n", dig);
			}
			else
			{
				printf("p\t");
			}
		}
		//printf("%c\n", str[i]);
	}
	return 0;
}
