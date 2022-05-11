#include <iostream>
#include <conio.h>

using namespace std;
double search(double* array, int size)
{
    double max = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}


double compare(double a, double b)
{
    return a > b ? a : b;
}
double recursive(double* array, int size)
{
    if (size < 1)
        return array[0];
    return compare(array[size], recursive(array, size - 1));
}

int main()
{
    double result = 0; 
    double recursive_result = 0;
    int size;
    cout << "Enter size of array";
    cin >> size;
    if (size < 1)
    {
        cout << "Wrong Input";
        cin >> size;
    }
    double* My_array = new double[size];
    
    for (int i = 0; i < size; ++i)
    {
        cout << "Input element value";
        cin >> My_array[i];
    }

    result = search(My_array, size);
    printf("max value = %lf", result);
    result = recursive(My_array, size);
    printf("max value = %lf", result);
}

