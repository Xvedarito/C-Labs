using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Дз
{
    class Program
    {
        static void Main(string[] args)
        {
            
            /*
            int a, b, f;
            a = 8;
            b = 4;
            f = 12;
            Console.WriteLine(a + b + f, a * b * f);
            Console.WriteLine(a * b * f);
            */

            /*
            const double USDtoBEL = 2.65;
            double USD;
            USD = double.Parse(Console.ReadLine());
            Console.WriteLine(USD + " USD в BEL= " + USDtoBEL * USD);
           
            string b;
            Console.WriteLine("Введите значение 1го числа: ");
            int a = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите значение 2го числа: ");
            b = Console.ReadLine();
            int c = Convert.ToInt32(b);
            Console.WriteLine("значение 1го и 2го числа = " + ((++a) + (--c)));
            */
            /*
            Console.WriteLine("Введите число ");
            int a = int.Parse(Console.ReadLine());
            double b = a % 2;
            if (b==0)
            {
                Console.WriteLine("Ваше число Четное!");
            }
            else
            {
                Console.WriteLine("Ваше число Нечетное!");
            }
            */
            //* Калькулятор Ниже
            while(true)
                //* Здесь попытка ловить ошибки. Где то ошибка и бесконечный цикл получил
                /*try
                {
                    Console.WriteLine("Введите 1е желаемое число");
                    double a = double.Parse(Console.ReadLine());

                    Console.WriteLine("Введите 2е желаемое число");
                    double b = double.Parse(Console.ReadLine());
                }
                catch (Exception)
                {
                    Console.WriteLine("Не удалось преобразовать строку в число. Ошибка");
                    Console.ReadLine();
                }
                */
                
            {
                Console.Clear();
            Console.WriteLine("Введите 1е желаемое число");
            double a = double.Parse(Console.ReadLine());
            Console.WriteLine("Введите 2е желаемое число");
            double b = double.Parse(Console.ReadLine());
            Console.WriteLine("Введите желаемое действие");
            //*Console.WriteLine("Деление на ноль вызовет ошибку");
            string symb = Console.ReadLine();
            
            
             //* Первый вариант через If
            if (symb=="+")
            {
                Console.WriteLine("1е число + 2е = " + (a + b));
            }
            else if (symb == "-") 
            {
                Console.WriteLine("1е число - 2е = " + (a - b));
            }
            else if (symb == "*") 
            {
                Console.WriteLine("1е число * 2е = " + (a * b));
            }
            else if (symb == "/") 
            {
                if (b == 0)
                    {
                        Console.WriteLine(0);
                    }
                    else
                    {
                        Console.WriteLine("1е число / 2е = " + (a / b));
                    }
            }
            else
            {
             Console.WriteLine("Ошибка. Неизвестное действие");
            }
                /*
                //Вариант 2 через switch
                switch (symb)
                {
                    case "+":
                        Console.WriteLine("1е число + 2е = " + (a + b));
                        break;
                    case "-":
                        Console.WriteLine("1е число - 2е = " + (a - b));
                        break;
                    case "*":
                        Console.WriteLine("1е число * 2е = " + (a * b));
                        break;
                    case "/":
                        if (b == 0)
                        {
                            Console.WriteLine(0);
                        }
                        else
                        {
                            Console.WriteLine("1е число / 2е = " + (a / b));
                        }
                        break;
                    default:
                        Console.WriteLine("Ошибка. Неизвестное действие");
                        break;
                */

                Console.ReadLine();
            }
        }
    }
    }

