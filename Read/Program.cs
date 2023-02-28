using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Read
{
    class Program
    {
        static void Main(string[] args)
        {
            char tasto;
            string parola = "", numeri = "";
            Console.WriteLine("inserire sequenza di caratteri");
            do
            {
                tasto = Convert.ToChar(Console.Read());
                if (Char.IsLetter(tasto))
                {
                    parola = parola + Convert.ToChar(tasto);
                }
                else if (tasto == ' ' || tasto==13)
                {
                    Console.WriteLine(parola);
                    parola = "";
                }
            } while (tasto != 13);
            Console.ReadLine(); // salta line feed
            Console.ReadLine(); // serve per bloccare programma
        }
    }
}
//la mamma va al mercato 
//la
//mamma
//va
//al
//mercato