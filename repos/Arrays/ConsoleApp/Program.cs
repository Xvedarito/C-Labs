using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            //arg[0]-path to log file
            //arg[1]-text event
            string target;
            target = Directory.GetCurrentDirectory() + "\\log.txt";
            
            if (!System.IO.File.Exists(target))
            {
                FileStream f= File.Create(target);
                f.Close();
            }
            string DT = DateTime.Now.ToString("dd-MM-yyyy-hh-mm-ss")+ "-" + args[0];
            if (args[0] != null && args.Length > 0)
            {
                DT += "-" + args[0];
            }
            Write_Log(target, DT);
        }
        static async Task Write_Log(string File, string text)
        {
            StreamWriter Log = new StreamWriter(File, append: true);
            await Log.WriteLineAsync(text);
            Log.Close();
        }
    }
}
