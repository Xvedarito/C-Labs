// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

Stack* Del_less_aver(Stack* b, double average, int& counter) {
    counter = 0;
    Stack* temporary, * source = b;
    temporary = source->next;
    while (temporary != NULL) {
        if (temporary->info < average) {
            source->next = temporary->next;
            delete temporary;
            temporary = source->next;
            counter++;
        }
        else {
            source = temporary;
            temporary = temporary->next;
        }
    }
    if (b->info < average) {
        temporary = b;
        b = b->next;
        delete temporary;
        counter++;
    }
    return b;
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
    int i, in, n, kod, sum, counter;
    double average, k;
    Stack* begin = NULL, * temporary;
    while (1) {
        cout << "\n\tCreate - 1\n\tAdd - 2\n\tView - 3\n\tTask_10 - 4 \n\tTask_14 - 5 \n\tDelete - 6 \n\tExit - any key. : ";
        cin >> kod;
        switch (kod)
        {
        case 1: case 2:
            if (kod == 1 && begin != NULL) {
                cout << "\n Clear memory!" << endl;
                break;
            }
            n = Input("\n Enter size: ");
            for (i = 0; i < n; i++) {
                in = Input(" Info: ");
                begin = InStack(begin, in);
            }
            if (kod == 1) cout << "\n Create " << n << endl;
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

        case 4:
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
            cout << "\n --- Stack before ---" << endl;
            View(begin);
            cout << "\n Average value: " << average << endl;
            begin = Del_less_aver(begin, average, counter);
            cout << " Size < " << average << " : " << counter << endl;
            cout << "\n --- Stack after ---" << endl;
            View(begin);
            break;
            
        case 5:
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