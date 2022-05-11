// Sem2Lab4Task11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>
using namespace std;

struct Stack {
    unsigned char info;
    Stack* next;
};

Stack* InS(Stack* peak, unsigned char in) {
    Stack* temp = new Stack;
    temp->info = in;
    temp->next = peak;
    return temp;
}

Stack* OutS(Stack* peak, unsigned char& out) {
    Stack* temp = peak;
    out = peak->info;
    peak = peak->next;
    delete temp;
    return peak;
}

Stack* Del_All(Stack* begin) {
    Stack* temp;
    while (begin != NULL) {
        temp = begin;
        begin = begin->next;
        delete temp;
    }
    return nullptr;
}


double input(const char* temp, unsigned char c)
{
    double x;
    cout << c << temp;
    while (!(cin >> x) or cin.get() != '\n') {
        cout << " Error, enter again:\n" << c << temp;
        cin.clear();
        cin.ignore(1024, '\n');
    }
    return x;
}

unsigned char* sort(unsigned char* Out) {
    unsigned char var[81];
    int m = 0;
    bool similar;
    for (int i = 0; Out[i] != '\0'; ++i) {
        if (!(Out[i] >= 'a' && Out[i] <= 'z')) continue;
        similar = true;
        for (int j = 0; j < i; ++j) {
            if (Out[i] == Out[j]) similar = false;
        }
        if (similar) {
            var[m] = Out[i];
            m++;
        }
    }
    var[m] = '\0';
    return var;
}

int Prior(unsigned char a) {
    switch (a) {
    case '^': return 4;
    case '*':   case '/': return 3;
    case '-':   case '+': return 2;
    case '(': return 1;
    }
    return 0;
}

int RPN(const unsigned char* In, unsigned char* Out) {
    Stack* Op = NULL;
    unsigned char a;
    int k, l = 0;
    for (k = 0; In[k] != '\0'; ++k) {
        if (In[k] >= 'a' && In[k] <= 'z')
            Out[l++] = In[k];
        
        else if (In[k] == '(')
            Op = InS(Op, In[k]);

        else if (In[k] == ')') {
            while ((Op->info) != '(') {
                Op = OutS(Op, a);
                if (!Op)
                    a = '\0';
                Out[l++] = a;
            }
            Op = OutS(Op, a);  
        }

        else if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/' || In[k] == '^') {
            while (Op != NULL && Prior(Op->info) >= Prior(In[k])) {
                Op = OutS(Op, a);
                Out[l++] = a;
            }
            Op = InS(Op, In[k]);
        }
    }
    while (Op != NULL) {
        Op = OutS(Op, a);
        Out[l++] = a;
    }
    Out[l] = '\0';
    return 0;
}

double Result(unsigned char* str, double arr[], int mode) {
    Stack* begin = NULL;
    int i;
    unsigned char ss, ss1, ss2, ssR = 'z' + 1, * var;
    double op1, op2, res;
    if (mode == 0) {
        cout << "\n Enter data:" << endl;
        var = sort(str);
        for (i = 0; var[i] != '\0'; ++i) {
            ss = var[i];
            if (ss >= 'a' && ss <= 'z') {
                arr[int(ss - 'a')] = input(" = ", ss);
            }
        }
    }
    for (i = 0; str[i] != '\0'; ++i) {
        ss = str[i];
        if (!(ss == '+' || ss == '-' || ss == '*' || ss == '/' || ss == '^'))
            begin = InS(begin, ss);
        else {
            begin = OutS(begin, ss2);
            begin = OutS(begin, ss1);
            op2 = arr[int(ss2 - 'a')];
            op1 = arr[int(ss1 - 'a')];
            switch (ss) {
            case '+': 	res = op1 + op2;   break;
            case '-': 	res = op1 - op2;   break;
            case '*': 	res = op1 * op2;   break;
            case '/':
                if (!(op2 == 0)) {
                    res = op1 / op2;   break;
                }
                else {
                    cout << "\n division by zero!" << endl;
                    begin = Del_All(begin);
                    return Result(str, arr, 0);
                };
            case '^':   res = pow(op1, op2);    break;
            }

            arr[int(ssR - 'a')] = res;
            begin = InS(begin, ssR);
            ssR++;
        }
    }
    return res;
}

unsigned char* InF() {
    cout << "\n Enter formula: ";
    unsigned char In[81];
    int i = 0, b = 0, e = 0;
    while (1) {
        In[i] = _getch();
        if (!(In[0] >= 'a' && In[0] <= 'z' || In[0] == '(')) continue;

        if (In[i] == 13) {
            if (In[1] == 13) continue;
            if (In[i - 1] == '+' || In[i - 1] == '-' || In[i - 1] == '*' || In[i - 1] == '/' || In[i - 1] == '^' || In[i - 1] == '(') continue;
            if (b != e) continue;
            else break;
        }

        if (In[i] == 8) {
            cout << '\b' << " " << '\b';
            if (In[i - 1] == '(') --b;
            if (In[i - 1] == ')') --e;
            In[i - 1] = '\0';
            --i;
            continue;
        }
        if (!(In[i] == '+' || In[i] == '-' || In[i] == '*' || In[i] == '/' || In[i] == '^' || In[i] == '(' || In[i] == ')' || (In[i] >= 'a' && In[i] <= 'z'))) continue;

        if ((In[i - 1] == '+' || In[i - 1] == '-' || In[i - 1] == '*' || In[i - 1] == '/' || In[i - 1] == '^' || In[i - 1] == '(') && !(In[i] >= 'a' && In[i] <= 'z' || In[i] == '(')) continue;
        if ((In[i - 1] >= 'a' && In[i - 1] <= 'z' || In[i - 1] == ')') && !(In[i] == '+' || In[i] == '-' || In[i] == '*' || In[i] == '/' || In[i] == '^' || In[i] == ')')) continue;

        if (In[i] == ')' && b == e) continue;
        if (In[i] == '(') b++;
        if (In[i] == ')') e++;
        cout << In[i];
        i++;
    }
    In[i] = '\0';
    return In;
}

int main()
{
    unsigned char In[81], Out[81], n[2], * in, InT[14] = { "a-(b/c*(d+e))" };
    int i, k = 0;
    double arr[50];
    In[0] = '\0';
    cout << "\n\t1 - Enter formula \n\t2 - View formula \n\t3 - Calculate expression \n\t4 - Test Task #11 \n\t0 - Exit" << endl;
    while (1) {
        cout << "\n\tMenu: ";
        do {
            n[0] = _getch();
            n[1] = '\0';
        } while (!(n[0] >= '0' && n[0] <= '4'));
        cout << n[0] << endl;
        system("cls");
        cout << "\n\t1 - Enter formula \n\t2 - View formula \n\t3 - Calculate expression \n\t4 - Test Task #11 \n\t0 - Exit" << endl;

        switch (n[0])
        {
        case '1':
            in = InF();
            for (i = 0; in[i] != '\0'; ++i) {
                In[i] = in[i];
                In[i + 1] = '\0';
            }
            RPN(In, Out);
            cout << "\n Result RPN: " << Out << endl;
            break;

        case '2':
            if (In[0] == '\0') {
                cout << "\n Enter formula!" << endl;
                break;
            }
            cout << "\n Expression: " << In << endl;
            cout << " Result RPN : " << Out << endl;
            break;

        case '3':
            if (In[0] == '\0') {
                cout << "\n Enter formula!" << endl;
                break;
            }
            cout << "\n Expression: " << In << endl;
            cout << " Result RPN: " << Out << endl;
            cout << "\n " << In << " = " << Result(Out, arr, 0) << endl;
            break;

        case '4':
            unsigned char OutT[81];
            double arr_t[50];
            cout << "\n Expression: " << InT << endl;
            RPN(InT, OutT);
            cout << "\n RPN: " << OutT << endl;
            arr_t[0] = 5.6;     cout << "\n a = " << arr_t[0] << endl;
            arr_t[1] = 3.2;     cout << " b = " << arr_t[1] << endl;
            arr_t[2] = 0.9;     cout << " c = " << arr_t[2] << endl;
            arr_t[3] = 1.7;     cout << " d = " << arr_t[3] << endl;
            arr_t[4] = 4.8;     cout << " e = " << arr_t[4] << endl;
            cout << "\n " << InT << " = " << Result(OutT, arr_t, 1) << endl;
            break;

        case '0':
            return 0;
        }
    }
}