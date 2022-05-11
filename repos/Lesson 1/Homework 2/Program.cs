using System;

namespace Homework_2
{
    class Program
    {
        static void Main(string[] args)
        {
            double EvenSumm = 0;
            double OddSumm = 0;

            int EvenCount = 0;
            int OddCount = 0;

            int InterecrionCount = 0;
            Console.WriteLine("Введите целый диапозон чисел:");
            int limit=int.Parse(Console.ReadLine());

            while (InterecrionCount < limit)
            {
                Console.WriteLine("Введите " + (InterecrionCount+1) + " желаемое число");
                double a=double.Parse(Console.ReadLine());
                double number = a % 2;
                if (number==0)
                {
                    EvenCount++;
                    EvenSumm += a;
                }
                else if (number != 0)
                {
                    OddCount++;
                    OddSumm += a;
                }
                InterecrionCount++;
            }
            Console.WriteLine("Количество четных = "+ EvenCount);
            Console.WriteLine("Количество нечетных = " + OddCount);
            Console.WriteLine("Сумма четных = " + EvenSumm);
            Console.WriteLine("Сумма нечетных = " + OddSumm);
        }
    }
}
