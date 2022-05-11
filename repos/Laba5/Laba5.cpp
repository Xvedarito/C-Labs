#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
//5.1
int main(int)
{
    srand(time(NULL));
    int size, value, min_i = 0, max_i = 0, transfer=0, rez=0;
    printf("Enter size of array \nsize = ");
    scanf_s("%d", &size);
    int* array = new int[size];
    printf("Print 0 to start manual \n or 1 to start auto \n v= ");
    scanf_s("%4d", &value);
    switch (value)
    {
        case 0:
            printf("You chosed manual mod. \n  ");
            for (int i = 0; i < size;i++)
            {
                fflush(stdin);
                printf("enter value of element value= ");
                scanf_s("%d", &array[i]);
                for (int j = 0;j <= size;j++) {
                    if (array[j] > array[max_i])
                    {
                        max_i = j;
                    }
                    else if (array[j] < array[min_i])
                    {
                        min_i = j;
                    }
                }
            }
            break;
        case 1:
            printf("You chosed auto mod");
            for (int i = 0; i <= size;i++)
            {
                array[i] = rand() %21 ;
                printf("\n %d", array[i]);
                for (int j = 0;j <= size;j++) {
                    if (array[j] > array[max_i])
                    {
                        max_i = j;
                    }
                    else if (array[j] < array[min_i])
                    {
                        min_i = j;
                    }
                }
            }
            break;

        }



    if (max_i < min_i) {
        /*max_i = max_i * min_i; //через 2 переменных
        min_i = max_i / min_i;
        max_i = max_i / min_i;
        через 3 переменных*/
        transfer = max_i;
        max_i = min_i;
        min_i = transfer;
        printf("\nmin_value= %d ", array[min_i]);
        printf("max_value = %d", array[max_i]);
        printf("\nmin_index = %d", min_i);
        printf("\nmax_index = %d", max_i);
        for (int k = min_i + 1;k <= max_i - 1;k++) {
            rez *= array[k];
        }
        printf("\nrez =%d", rez);
    }
    delete []array;

    return 0;
}