using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Triangle
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Введите значение длины: ");
            int Hight = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите значение ширины: ");
            int Width = int.Parse(Console.ReadLine());
            int Width2 = Width;
            int Width3 = 0;
            int Width4 = Width;
            while (true)
            { 
            for (int C1=0;C1<Hight;C1++)
            {
                for (int C2=0;C2<Width2;C2++)
                {
                    Console.Write("*");
                   
                }
                Width2--;
                Console.WriteLine();
            }
            
            for (int D1 = 0; D1 < Hight; D1++)
            {
                for (int D2 = 0; D2 <= Width3; D2++)
                {
                    Console.Write("*");

                }
                Width3++;
                Console.WriteLine();
            }
                Width2 = Width;
                Width3 = 0;


                for (int D1 = 0; D1 < Hight; D1++)
                {
                    for (int C2 = Hight; C2 > D1; C2--)
                    {
                        Console.Write(" ");

                    }
                    for (int D2 = 0; D2 <= D1; D2++)
                    {
                        Console.Write("*");

                    }
                    
                    Console.WriteLine();
                }
                Width2 = Width;
                Width3 = 0;
                Console.ReadLine();
                /*
                 //*Треугольник
                int W = 1;

                int Count = 0;

                for (int h = 0;  5>= h; h++)
                    {


                    for (; W <= Count; W++) 
                    {
                        Console.Write("1");
                    }
                    Count++; 
                    W = 1;
                    Console.WriteLine("1");
                }
                 */
            }
        }
    }
}
