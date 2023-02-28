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
            bool trovato = false;
            const int maxParole=3;
            int contaparole=0;
            string parola = "", numeri = "";
            string[] dizionario = new string[maxParole];
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
                    if (contaparole == maxParole)
                    {
                        Console.WriteLine("dizionario pieno");
                    }
                    else
                    {
                        trovato = false;
                        for (int i = 0; i < contaparole && !trovato; i++)
                        {
                            trovato = parola == dizionario[i];
                        }
                        if (!trovato)
                        {
                            dizionario[contaparole] = parola;
                            contaparole++;
                        }
                        else
                        {
                            trovato = true;
                        }
                        parola = "";
                    }
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