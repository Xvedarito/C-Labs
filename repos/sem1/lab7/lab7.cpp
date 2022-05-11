#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;//9 задание

char* inputData(unsigned int* size) {

    const int maxStringSize = 82;

    char prevChar = ' ';

    char* buffer = new char[maxStringSize];
    for (int i = 0; i < maxStringSize; i++) {
        buffer[i] = ' ';
    }

    int buffLen = 0;
    while (true) {
        char currChar = _getch();
        bool addToBuffer = false;
        if (currChar == '\r') {
            break;
        }
        if (((currChar >= '0' && currChar <= '9') || (currChar == ' ' && prevChar != ' ')) && buffLen < maxStringSize - 2) {
            putchar(currChar);
            prevChar = currChar;
            buffer[buffLen] = currChar;
            buffLen++;
        }
    }
    *size = buffLen + 1;
    return buffer;
}

int substr_to_int(char* str, unsigned int start, unsigned int end) {
    char* sub = new char[end - start + 1];
    memcpy(sub, str + start, end - start);
    sub[end - start] = '\0';
    int toReturn = stoi(sub);
    delete[] sub;
    return toReturn;
}

void number_sort(int* nums, unsigned int numberOfNums) {
    int j = 0;
    bool swap = true;
    int temp;
    while (swap)
    {
        swap = false;
        j++;
        for (unsigned int l = 0; l < numberOfNums - j; l++)
        {
            if (nums[l] > nums[l + 1])
            {
                temp = nums[l];
                nums[l] = nums[l + 1];
                nums[l + 1] = temp;
                swap = true;
            }
        }
    }
}

int main()
{
    printf("%s", "Input numbers separated by spaces\n");
    unsigned int strLen = 0;
    char* input = inputData(&strLen);

    unsigned int numberOfWords = 0;

    for (unsigned int i = 0; i < strLen; i++) {
        if (input[i] == ' ' && input[i - 1] != ' ') {
            numberOfWords++;
        }
    }
    if (numberOfWords == 0) {
        printf("Invalid input\n");
        return 10;

    }
    printf("\nNumber of words: %d", numberOfWords);

    int* nums = new int[numberOfWords];
    unsigned int lastIndex = 0;
    unsigned int ind = 0;
    for (unsigned int i = 0; i < strLen; i++) {
        if (input[i] == ' ' && input[i - 1] != ' ') {
            nums[ind] = substr_to_int(input, lastIndex, i + 1);
            lastIndex = i;
            ind++;
        }
    }

    printf("\n\nSort:");
    number_sort(nums, numberOfWords);
    for (unsigned int i = 0; i < numberOfWords; i++) {
        printf("\n%d", nums[i]);
    }

    return 0;
}