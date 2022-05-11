#include <iostream>


using namespace std;

void ShowArray(int n, int m, int**array)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0;j < m;j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}



int main()
{
    bool Check=false;
    int Result=1, n, m, ResultSize=0;
    int** array;
    cout << "Input the number of strings:\t"; cin >> n; cout << endl;
    while (n < 1)
    {
        cout << "Error! Your matrix should has 1 or more strings!\nInput the number of strings again:\t";
        cin >> n; cout << endl;
    }
    cout << "Input the number of columns:\t"; cin >> m; cout << endl;
    while (m < 1)
    {
        cout << "Error! Your matrix should has 1 or more columns!\nInput the number of columns again:\t";
        cin >> m; cout << endl;
    }
    array = new int* [n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m;j++)
        {
            cout << "Intput element number [" << i+1 << "][" << j+1 << "] :\t";
            cin >> array[i][j]; cout << endl;
        }
    }
    cout << "Matrix:";
    ShowArray(n, m, array);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (array[i][j] > 0)
            {
                ResultSize++;
            }
        }
        if (ResultSize == m)
        {
            Check = true;
            int* ResultString = new int[ResultSize];
            for (int j = 0;j < m;j++)
            {
                ResultString[j] = array[i][j];
                 Result*= ResultString[j];
            }
            delete[]ResultString;
        }
        ResultSize = 0;
    }
    if (Check)
    {
        cout << "\nThe answer is:\t" << Result<<endl;
    }
    else
    {
        cout << "The answer is:\t 0\n";
    }
    

    system("pause");
    return 0;
}




