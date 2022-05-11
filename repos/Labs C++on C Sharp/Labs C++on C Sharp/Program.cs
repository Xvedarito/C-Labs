using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Labs_C__on_C_Sharp
{
    class Program
    {
        double Factorial(int i)
        {
            if (i <= 1)
                return 1;
            return i * Factorial(i - 1);
        }
        static void Main(string[] args)
        {
            double a, b, h, S=0, Y;

            Console.Write("input min a = ");
                a = Double.Parse(Console.ReadLine());
            Console.Write("input max b = ");
                b = Double.Parse(Console.ReadLine());
            Console.Write("input step h = ");
                h = Double.Parse(Console.ReadLine());
            Console.Write("input interation number n = ");
                int n = int.Parse(Console.ReadLine());
            for (double x = a; x < b; x += h)
                {
                    Console.WriteLine("\n Y = Sin(x) = ");
                    Console.Write(Y = Math.Sin(x));
                    for (int k = 0; k < n; k++)
                        {
                            S += Math.Pow(-1, k) * Math.Pow(x, 2*k + 1) / Factorial(2*k+1);
                        }
                }
        }
        
    }

}

