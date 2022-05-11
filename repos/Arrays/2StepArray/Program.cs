using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2StepArray
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            Console.WriteLine("Enter Hight: ");
            int LengthStroke = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter Width: ");
            int LengthCollon = int.Parse(Console.ReadLine());
            int[,] myArray = new int [LengthStroke,LengthCollon]; 
            for (int i = 0; i < LengthStroke; i++ )
            {
                for (int j = 0; j < LengthCollon; j++)
                {
                    myArray[i, j] = rnd.Next(10,99);
                }
            }
            
            for (int i = 0; i < LengthStroke; i++)
            {
                string str = "";
                for (int j = 0; j < LengthCollon; j++)
                {
                    str = str + myArray[i, j].ToString() + "*";
                }
                str = str.Remove(str.Length - 1);
                Console.WriteLine(str );
            }
        }
    }
}
