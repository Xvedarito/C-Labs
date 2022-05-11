using System;
using System.Globalization;


namespace Lesson_1
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            
            System.Console.WriteLine("Привет Мир!!");
            System.Console.WriteLine("Hello World!!");      

            string msg = "Тип: {0,6}|  .NET {1,6}|   Размер = {2}|  MIN = {3}| MAX = {4}|";
            Console.Title = "Типы данных в C#";
            Console.WriteLine(string.Format(msg, "byte", typeof(byte).Name, sizeof(byte), byte.MinValue, byte.MaxValue));
            Console.WriteLine(string.Format(msg, "int", typeof(int).Name, sizeof(int), int.MinValue, int.MaxValue));
            Console.WriteLine(string.Format(msg, "uint", typeof(uint).Name, sizeof(uint), uint.MinValue, uint.MaxValue));

            const bool Enable = true ;
            const bool Disable = false;
            Console.WriteLine(Enable);
                ДЗ
            int a,b,f;
            a = 8;
            b = 4;
            f = 12;
            Console.WriteLine(a+b+f, a*b*f);
            Console.WriteLine(a * b * f);
           
            const double USDtoBEL = 2.65;
            double USD ;
            USD = double.Parse(Console.ReadLine());
            Console.WriteLine(USD + " USD в BEL= " + USDtoBEL*USD);
                Сумма 2х чисел
            string b;
            Console.WriteLine("Введите значение 1го числа: ");
            int a = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите значение 2го числа: ");
            b = Console.ReadLine();
            int c = Convert.ToInt32(b);
            Console.WriteLine("значение 1го и 2го числа = "+ (a + c));
             
                Попытка Изменить прочитку плавуюещей точки
            string f = "1.9";
            NumberFormatInfo numberFormatInfo = new System.Globalization(NumberFormatInfo())
            {
                NumberDecimalSeparator = ".",
            };
            double a = Convert.ToDouble(f, numberFormatInfo); 
            */
            int b = int.Parse(Console.ReadLine());
            for(int i = int.Parse(Console.ReadLine()); i<=b; i++)
            {
                Console.WriteLine("i = "+i);
            }
        }

    }
}
