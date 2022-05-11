using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Function
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int Arr_length_stroke = rnd.Next(0, 99); //длина строки массива 
            int Arr_length_collon = rnd.Next(0, 10);//длина колонки массива
            //int[,] my_Arr = new int[Arr_length_stroke, Arr_length_collon];
            int NumberSearch = rnd.Next(0, 20); //вводим искомое число
            IndexFirst(Arr_length_collon, Arr_length_stroke, NumberSearch);
        }
        static void IndexFirst(int Arr_length_stroke, int Arr_length_collon, int NumberSearch)
        {
            int Index_Out_Stroke = 0;
            int Index_Out_Collon = 0;
            Random rnd = new Random();
            //int Arr_length = rnd.Next(0, 99); длина массива
            //int NumberSearch2 = int.Parse(Console.ReadLine()); //вводим искомое число
            int[,] my_Arr = new int[Arr_length_stroke, Arr_length_collon];
            if (Arr_length_stroke == 0 || Arr_length_collon == 0)
            {
                Console.WriteLine("Массив не содержит симоволов");
                Console.ReadLine();
            }
            else
            {
                for (int k = 0; k < Arr_length_stroke; k++)
                {
                    for (int m = 0; m < Arr_length_collon; m++)
                    {
                        my_Arr[k, m] = rnd.Next(0, 10000);
                    }
                }

                for (int j = 0; j < Arr_length_stroke; j++)
                    {
                        for (int i = 0; i < Arr_length_collon; i++)
                        {
                            if (my_Arr[j, i] == NumberSearch)
                            {
                                Index_Out_Stroke = j;
                                Index_Out_Collon = i;
                                Console.WriteLine("Искомое число находится под индексом строки = " + Index_Out_Stroke + "и индексом колонны = " + Index_Out_Collon);
                                break;
                            }
                            else
                            {
                                Index_Out_Stroke = 0;
                                Index_Out_Collon = 0;
                            }
                        }
                    }
                if (Index_Out_Stroke == 0 && Index_Out_Collon == 0)
                {
                    Console.WriteLine("Искомое число не найдено");
                }
            }
        }
    }
}
