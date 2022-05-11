// Sem2Lab2Task10_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
using namespace std;

struct Stack {
    int info;
    Stack* next;
};

Stack* InStack(Stack* source, int in) {
    Stack* temporary = new Stack;
    temporary->info = in;
    temporary->next = source;
    return temporary;
}

void View(Stack* temporary) {
    while (temporary != NULL) {
        cout << temporary->info << " ";
        temporary = temporary->next;
    }
    cout << endl;
}

void Del_All(Stack*& source) {
    Stack* temporary;
    while (source != NULL) {
        temporary = source;
        source = source->next;
        delete temporary;
    }
}

void Del_Task(Stack*& current) {
    Stack* source = current;
    while (current->next != NULL && current->next->next != NULL) {
        Stack* item_to_delete = current->next;
        current->next = current->next->next;
        delete item_to_delete;
        current = current->next;
    }
    current = source;
}

Stack* Del_less_aver(Stack* peak, double average, int& counter_to_del) {
    counter_to_del = 0;
    Stack* temporary, * source = peak;
    temporary = source->next;
    while (temporary != NULL) {
        if (temporary->info < average) {
            source->next = temporary->next;
            delete temporary;
            temporary = source->next;
            counter_to_del++;
        }
        else {
            source = temporary;
            temporary = temporary->next;
        }
    }
    if (peak->info < average) {
        temporary = peak;
        peak = peak->next;
        delete temporary;
        counter_to_del++;
    }
    return peak;
}

int Input(const char* temporary) {
    char s[20];
    int i = 0;
    cout << temporary;
    while (1) {
        s[i] = _getch();
        if (s[i] == 13) break;
        if (!(s[i] >= '0' && s[i] <= '9')) continue;
        cout << s[i];
        i++;
    }
    s[i] = '\0';
    cout << endl;
    return atoi(s);
}

int main() {
    int i, in, n, menu, sum, counter;
    double average, k;
    Stack* begin = NULL, * temporary;
    while (1) {
        cout << "\n\tCreate - 1\n\tAdd - 2\n\tView - 3\n\tDelete_Below_Average - 4 \n\tDelete_Every_Second - 5 \n\tDelete - 6 \n\tExit - any key. : ";
        cin >> menu;
        switch (menu)
        {
        case 1: case 2:
            if (menu == 1 && begin != NULL) {
                cout << "\n Clear memory!" << endl;
                break;
            }
            n = Input("\n Enter size: ");
            for (i = 0; i < n; i++) {
                in = Input(" Info: ");
                begin = InStack(begin, in);
            }
            if (menu == 1) cout << "\n Create " << n << endl;
            else cout << "\n Add " << n << endl;
            break;

        case 3:
            if (!begin) {
                cout << "\n Stack empty!" << endl;
                continue;
            }
            cout << "\n --- Stack ---" << endl;
            View(begin);
            break;

        case 4: // Task 10
            if (!begin) {
                cout << "\n Stack empty!" << endl;
                continue;
            }
            k = 0; sum = 0;
            temporary = begin;
            while (temporary != NULL) {
                sum += temporary->info;
                temporary = temporary->next;
                k++;
            }
            average = sum / k;
            begin = Del_less_aver(begin, average, counter);
            cout << "\naverage value is : " << average  <<"| Number of elements to remove: " << counter << endl;
            cout << "\n --- Stack after ---" << endl;
            View(begin);
            break;

        case 5: //Task 14
            Del_Task(begin);
            cout << "\n --- Stack after ---" << endl;
            View(begin);
            break;
        case 6:
            Del_All(begin);
            cout << "\n Memory cleared!" << endl;
            break;

        default:
            if (begin != NULL) Del_All(begin);
            return 0;
        }
    }
}