
#include <iostream>
#include <conio.h>
using namespace std;

struct List {
    int info;
    List* prev, * next;
};

void Create(List** peak, List** tail, int in) {
    List* temporary = new List;
    temporary->info = in;
    temporary->next = temporary->prev = NULL;
    *peak = *tail = temporary;
}

void Add(int direction, List** peak, List** tail, int in) {
    List* temporary = new List;
    temporary->info = in;
    if (direction == 0) {
        temporary->prev = NULL;
        temporary->next = *peak;
        (*peak)->prev = temporary;
        *peak = temporary;
    }
    else {
        temporary->next = NULL;
        temporary->prev = *tail;
        (*tail)->next = temporary;
        *tail = temporary;
    }
}

void View(int direction, List* temporary) {
    List* source = temporary;
    while (temporary != NULL) {
        cout << temporary->info << " ";
        if (direction == 0) temporary = temporary->next;//from start
        else  temporary = temporary->prev;//from end
    }
    temporary = source;
}

void Del_All(List*& source) {
    List* temporary;
    while (source != NULL) {
        temporary = source;
        source = source->next;//delete eveything so doesnt matter which side choose to start with
        delete temporary;
    }
}

List* Del_less_aver(List* peak, double& average, int& counter_to_delete) {
    if (peak == NULL)
        return 0;
    double k = 0; int sum = 0;
    List* temporary = peak, * source = peak;
    while (temporary != NULL) {
        sum += temporary->info;
        temporary = temporary->next;
        k++;// counter of all elements
    }
    average = sum / k;
    temporary = source->next;
    while (temporary != NULL) {
        if (temporary->info < average) {
            if (temporary->prev != NULL) {
                (temporary->prev)->next = temporary->next;
            }
            if (temporary->next != NULL) {
                (temporary->next)->prev = temporary->prev;
            }
            delete temporary;
            temporary = source->next;
            counter_to_delete++;
        }
        else {
            source = temporary;
            temporary = temporary->next;
        }
    }
    if (peak->info < average) {
        temporary = peak;
        temporary = peak->next;
        temporary->prev = NULL;
        delete temporary;
        counter_to_delete++;
    }
    return peak;
}

void Del_Second(List*& first, List*& last, int direction) {
    List* source_first = first;
    List* source_last = last;
    if (direction == 0) {
        while (first->next != NULL && first->next->next != NULL) {
            List* item_to_delete = first->next;
            first->next = first->next->next;
            delete item_to_delete;
            first = first->next;
        }
        first = source_first;
    }
    else {
        while (last->prev != NULL && last->prev->prev != NULL) {
            List* item_to_delete = last->prev;
            last->prev = last->prev->prev;
            delete item_to_delete;
            last = last->prev;
        }
        last = source_last;
    }
}

int Input(const char* t) {
    char s[20];
    int i = 0;
    cout << t;
    while (1) {
        s[i] = _getch();
        if (i == 0 && s[0] == '-') {
            cout << s[0];
            i++;
            continue;
        };
        if (s[i] == 13) break;
        if (!(s[i] >= '0' && s[i] <= '9')) continue;
        cout << s[i];
        i++;
    }
    s[i] = '\0';
    cout << endl;
    return atoi(s);
}
int main()
{
    List* begin = NULL, * end = NULL, * temporary;
    int i, n, in, menu, direction, counter = 0;
    double average = 0;

    while (true) {
        cout << "\n\tCreate - 1\n\tAdd - 2\n\tView - 3\n\tDelete_Below_Average - 4 \n\tDelete_Every_Second - 5 \n\tDelete - 6 \n\tExit - any key. : ";
        menu = Input(": ");
        switch (menu) {
        case 1:
            if (begin != NULL) {
                cout << "\nClear memory!" << endl;
                break;
            }
            in = Input("\nStart info: ");
            Create(&begin, &end, in);
            cout << "Start Created: " << begin->info << endl;
            break;

        case 2:
            if (!begin) {
                cout << "\nCreate List!" << endl;
                continue;
            }
            do {
                n = Input("\nSize = ");
            } while (!(n > 0));
            do {
                direction = Input("\nAdd to start - 0 \nAdd to end - 1 :  ");
            } while (direction != 0 && direction != 1);
            for (i = 0; i < n; i++) {
                in = Input("Info: ");
                Add(direction, &begin, &end, in);
            };
            temporary = begin;
            direction = 0;
            View(direction, temporary);
            break;

        case 3:     if (!begin) {
            cout << "\nEmpty List!" << endl;
            break;
        }
              cout << "\n--- From Start ---" << endl;
              View(0, begin);
              cout << "\n--- From End ---" << endl;
              View(1, end);
              break;

        case 4:
            if (!begin) {
                cout << "\nList is empty!" << endl;
                continue;
            }
            begin = Del_less_aver(begin, average, counter);
            cout << "\naverage value is : " << average << "| Number of elements to remove: " << counter << endl;
            cout << "\n--- List after(from the start) ---" << endl;
            View(0, begin);
            cout << "\n--- List after(from the end) ----" << endl;
            View(1, end);
            break;

        case 5: //Task 14
            direction = Input("\nRemove from start - 0 \nRemove from end - 1 :  ");
            Del_Second(begin, end, direction);
            cout << "\n--- List after(from the start) ---" << endl;
            View(0, begin);
            cout << "\n--- List after(from the end) ----" << endl;
            View(1, end);
            break;

        case 6:
            Del_All(begin);
            cout << "\nMemory Cleared!" << endl;
            break;

        default:  if (begin != NULL)
            Del_All(begin);
            return 0;
        }
    }
}