using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Инкремент_и_Декримент
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 0;
            int b = 5;
            /*Console.WriteLine(++a*--b);

            Console.WriteLine(a++ * a);

            Console.WriteLine("префикс меняем на постфикс = " + ++a * b--);
            Console.WriteLine(a);
            Console.WriteLine(b);
            */
            Console.WriteLine("не понимаю логики = " + a++ * --b);
        }
    }
}
