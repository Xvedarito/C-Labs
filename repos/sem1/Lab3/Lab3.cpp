#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int main(int)
{
    srand(time(NULL));
    int value, min_i = 0, max_i = 0, transfer = 0, rez = 0, size = 0;
    printf("Input array size = ");
    scanf_s("%8d", &size); 
    printf("Print 0 to start manual or 1 to start auto \n v= ");
    scanf_s("%8d", &value);
    int* array = new int[size];
    switch (value)
    {
    case 0:
        printf("You chose manual mod. \n  ");
        printf("Input array \n  ");
        for (int i = 0; i < size; i++)
        {
            fflush(stdin);
            scanf_s("%d", &array[i]);
        }
        break;
    case 1:
        printf("You chose auto mod");
        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 21 - 10;
            printf("\n %d", array[i]);
        }
        break;
    default: 
        printf("wrong input");
        return 0;
    }
    for (int j = 0; j < size; j++) {
        if (array[j] > array[max_i])
        {
            max_i = j;
        }
        else if (array[j] < array[min_i])
        {
            min_i = j;
        }
    }
    printf("\nmin= %d ", array[min_i]);
    printf("max= %d", array[max_i]);
    if (max_i < min_i) {
        transfer = max_i;
        max_i = min_i;
        min_i = transfer;
    }
    printf("\nmin_i= %d", min_i);
    printf(" max_i= %d", max_i);
    if (max_i - min_i == 1) {
        printf("\nrez cant be found");
    }
    else {
        for (int k = min_i + 1; k <= max_i - 1; k++) {
            rez += array[k];
        }
        printf("\nrez=%d", abs(rez));
    }
    return 0;
}
