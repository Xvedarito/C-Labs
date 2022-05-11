#include <algorithm>
#include <iostream>

using namespace std;

int func(int* my_array, int left, int right, int key) {
	int middle = 0;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (key < my_array[middle])
			right = middle - 1;
		else if (key > my_array[middle])
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}

int rec_func(int* my_array, int left, int right, int key)
{
	if (left > right) return -1;
	int middle = (left + right) / 2;
		if (key < my_array[middle]) 
			rec_func(my_array, left, middle - 1, key);
		else 
			if (key > my_array[middle]) 
				rec_func(my_array, middle + 1, right, key);
		else 
				return middle;
		
}
int input_data() {
	int value;
	while (!(cin >> value) || (cin.get() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Please enter numbers" << endl;
	}
	return value;
}


int main()
{
	int size, key, index;
	do {
		cout << "enter size of array: ";
		size = input_data();
		if (size <= 1)
			cout << "Error size" << endl;
	} while (size < 1);
	int* my_array = new int[size];
	for (int i = 0; i < size; i++)
	{
		my_array[i] = input_data();
	}

	for (int i = 0; i < size; i++) // вывод массіва
	{
		cout << my_array[i] << "  |  ";
	}
	cout << "\nenter key: ";
	key = input_data();

	index = func(my_array, 0, size, key);
	if (index < 0) cout << "\nNot found!" << endl;
	else cout << "\nindex from function: " << index << endl;
	index =  rec_func(my_array, 0, size, key);
	if (index < 0) cout << "\nNot found!" << endl;
	else cout << "\nindex from function: " << index << endl;
}





/*int part(int my_array[], int low, int high)
{
	int pike = my_array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (my_array[j] <= pike)
		{
			i++;
			swap(my_array[i], my_array[j]);
		}
		swap(my_array[i+1], my_array[j]);
		return(i + 1);
	}
}

void bubble_sort(int my_array[], int low, int high)
{
	if (low < high)
	{
		int pi = part(my_array, low, high);
		bubble_sort(my_array, low, pi - 1);
		bubble_sort(my_array, pi + 1, high);
	}
}
*/