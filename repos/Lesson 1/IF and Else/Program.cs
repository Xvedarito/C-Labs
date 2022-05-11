using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IF_and_Else
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            *Логические Операторы
                && скоращенное И(проверяет только одну часть)
                || Сокращенное Или(проверяет только одну часть)
                & И
                || Или
                ! Не(Унарное)
            */

            //* Условыый оператор switch. Умеет работать со строками и числами

            int a=int.Parse(Console.ReadLine());
            switch(a)
            {
                case 1:
                    case 2:
                        Console.WriteLine("Вы ввели число 1 или 2");
                        break;
                default:
                    Console.WriteLine("Я не знаю что делать с этим числом");
                    break;


            }
        }
    }
}
