using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Сравнение
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите значение а");
            int a = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите значение b");
            int b = int.Parse(Console.ReadLine());
            Console.WriteLine("a==b = " + (a == b));
            Console.WriteLine("a!=b = " + (a != b));
            Console.WriteLine("a<=b = " + (a <= b));
            Console.WriteLine("a>=b = " + (a >= b));
            Console.WriteLine("a<b = " + (a < b));
            Console.WriteLine("a>b = " + (a > b));
        }
    }
}
