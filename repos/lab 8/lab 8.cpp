#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <io.h>
//#include <fstream>
using namespace std;
struct TZap {
    char FIO[25];
    int YoB;
    int group;
    int math;
    int physics;
    int chemestry;
    double s_b;
} Zap;
int size = sizeof(TZap);
FILE* F;
char File_Zap[] = "zapisi.dat";
//char File_Zap[] = "rezult.txt";
void Out(TZap, int id);
int record_count;

TZap* Read_Data(char *File) {
    int file_descryptor;
    long len;
    F = fopen(File, "rb");
    file_descryptor = _fileno(F);
    len = _filelength(file_descryptor);
    record_count = len / size;
    TZap* array_data = new TZap[record_count];
    // Считываем записи из файла в динамический массив
    for (int i = 0; i < record_count; i++)
        fread((array_data + i), size, 1, F);
    fclose(F);
    return array_data;//unsorted
}

TZap* Sort_Data(TZap* Array_unsorted)
{

    for (int i = 0; i < record_count - 1; i++)
        for (int j = i + 1; j < record_count; j++)
            if (Array_unsorted[i].s_b > Array_unsorted[j].s_b) {
                TZap st = Array_unsorted[i];
                Array_unsorted[i] = Array_unsorted[j];
                Array_unsorted[j] = st;
            }
    return Array_unsorted;//sorted to be sure
}

int main()
{
    int menu_value, i = 0, j, ID;
    long len;
    TZap st, * array_data, * sorted_data;
    while (true) {
        puts("\n Create - 1\n Add - 2\n View - 3\n Sort - 4\n Personal Task(8.1) - 5\n Delete Record - 6\n EXIT - 0 \n");
        scanf_s("%d", &menu_value);
        switch (menu_value) {
        case 1://c
            if ((F = fopen(File_Zap, "wb")) == NULL) {
                puts("\n Create ERROR!");
                return 0;
            }
            fclose(F);
            printf("\n Create New File %s !\n", File_Zap);
            break;
        case 2://add
            F = fopen(File_Zap, "ab");
            printf("\n F.I.O. - ");
            fflush(stdin);
            scanf_s("%c", &Zap.FIO);
            gets_s(Zap.FIO);
            printf("\n Group Number - ");
            scanf_s("%d", &Zap.group);
            printf("\n Math Mark - ");
            scanf_s("%d", &Zap.math);
            printf("\n Physics Mark - ");
            scanf_s("%d", &Zap.physics);
            printf("\n Chemestry Mark - ");
            scanf_s("%d", &Zap.chemestry);
            Zap.s_b = (Zap.math + Zap.physics + Zap.chemestry) / 3.0;
            fwrite(&Zap, size, 1, F);
            fclose(F);
            break;
        case 3://veiw
            default:
                array_data = Read_Data(File_Zap);
                printf("\nInformations ----------------------------------------");
                printf("\n%3s|%-25s|%-10s|%-6s ", "ID", "FIO", "Group", "GPA");
                for (i = 0; i < record_count; i++) {
                    Out(array_data[i], i);
                }
                printf("\n-----------------------------------------------------");
        break;
        case 4://sort
                array_data = Read_Data(File_Zap);
                sorted_data = Sort_Data(array_data);
                printf("\nInformations ----------------------------------------");
                printf("\n%3s|%-25s|%-10s|%-6s ", "ID", "FIO", "Group", "GPA");
                for (i = 0; i < record_count; i++) {
                    Out(sorted_data[i], i);
                }
                printf("\n-----------------------------------------------------");
            break;
        case 5://personal task
            array_data = Read_Data(File_Zap);
            printf("\nE L I T E -------------------------------------------\n");
            printf("\n%3s|%-25s|%-10s|%-6s ", "ID", "FIO", "Group", "GPA");
            for (i = 0; i < record_count; i++) {
                fread((array_data + i), size, 1, F);
                if (array_data[i].s_b > 7) {
                    Out(array_data[i], i);
                }
            }
            printf("\n-----------------------------------------------------\n");
            break;
        case 6://delete

            array_data = Read_Data(File_Zap);
            printf("\nEveryone ----------------------------------------------");
            printf("\n%3s|%-25s|%-10s|%-6s ", "ID", "FIO", "Group", "GPA");
            for (i = 0; i < record_count; i++) {
                Out(array_data[i], i);
            }
            printf("\n Enter the ID for deletion\n");
            scanf_s("%d", &ID);
            for (i = 0; i < record_count; i++) {
                if (ID != i){
                Out(array_data[i], i);
                }
            }
            
            printf("\n-----------------------------------------------------\n");
            break;
        case 0://exit
            fclose(F);
            return 0;
        }

    }
}
void Out(TZap z, int ID) // Вывод записи на экран 
{
    printf("\n%3d|%-25s|%-10d|%-6.3lf ",ID, z.FIO, z.group , z.s_b );
}
