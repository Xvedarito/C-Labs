using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Massive_function
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int limit = rnd.Next(1, 10);
            for (int counter = 0; counter<limit; counter++)
            { 
            int Length = rnd.Next(1, 50);
            int Index = rnd.Next(0, Length);
            int multiplier = rnd.Next(1, 10);
            Console.WriteLine("Итерация № "+counter+" со значением указанного индекса = "+Array_Back(Length, multiplier, Index));
            }
        }
        static int Array_Back(int L,int multiplier, int Index)
        {
            if (Index > L)
                return -1;
            int[] arr = new int[L];
            for (int i = 0; i < L; i++) 
            {
                arr[i] = i * multiplier;
            }
            return arr[Index];
        }

    }
}
