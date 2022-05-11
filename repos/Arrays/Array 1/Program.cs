using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Array_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите значение Количество элементов массива = ");
            uint L = uint.Parse(Console.ReadLine());
            int[] Array1 = new int [L];
            double Numbers;
            double EvenSumm = 0;
            double OddSumm = 0;
            int min = 0;
            for (uint i= 0; i<L; i++)
                {
                    Console.WriteLine("Введите значение " + i + " Элемента = ");
                    int IElement = int.Parse(Console.ReadLine());
                    min = Array1[0];
                    Array1[i] = IElement;
                    Numbers = Array1[i];
                    if (Numbers % 2 == 0)
                    {
                        Console.WriteLine("Элемент № " +  i + " Четный");
                        EvenSumm += Array1[i];     
                    }
                    else
                    {
                        Console.WriteLine("Элемент № " + i + " Нечетный");
                        OddSumm += Array1[i];
                    }
            /*        if (IElement<min)
                    {
                    continue;
                    }
                    else
                    {
                    min = Array1[i];
                    continue;
                    }
             */       
                for (int b =0; b<L; b++)
                {
                if (Array1[b] < min)
                {
                    min = Array1[b];
                }
                else
                    continue;
                }
                }
           
            Console.WriteLine("min = " + min);
            Console.WriteLine("Сумма Нечетных чисел списка = " + OddSumm);
            Console.WriteLine("Сумма Четных чисел списка = " + EvenSumm );
            Console.ReadLine();
        }
    }
}
