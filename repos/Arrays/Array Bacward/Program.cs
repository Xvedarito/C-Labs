using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Array_Bacward
{
    class Program
    {
        static void Main(string[] args)
        {

 
            int[] Array = { 2,3,45};
            int min = Array[0];
            for (int i=0;i<Array.Length;i++)
            {
                if (min > Array[i])
                    min = Array[i];
            }
            Console.WriteLine("min =" + min);
            Console.ReadLine();
        }
    }
}
