using System;

namespace ElencoTelefonico
{
    internal class Program
    {
        static void Main(string[] args)
        {
            const int maxOpzione = 3;
            const int nomiMax = 2;
            int telefoni = 0;
            string[] nomeCognome = new string[nomiMax];
            string[] telefono = new string[nomiMax];
            int opzione;
            do
            {

                do
                {
                    Console.Clear();
                    Console.WriteLine("=== Agenda Telefonica ===");
                    Console.WriteLine("[1] Inserimento {inserire cognome, nome, numero di telefono}");
                    Console.WriteLine("[2] Visualizzazione numeri di telefono");
                    Console.WriteLine("[3] Fine");
                    opzione = Convert.ToInt32(Console.ReadLine());

                } while (opzione < 1 || opzione > maxOpzione);
                switch (opzione)
                {
                    case 1:
                        if (telefoni != nomiMax)
                        {
                            Console.WriteLine("Inserire nome e cognome");
                            nomeCognome[telefoni] = Console.ReadLine();
                            //while (nomeCognome[telefoni] == "")
                            //{
                            //    Console.WriteLine("Hai premuto invio per sbaglio");
                            //    nomeCognome[telefoni] = Console.ReadLine();
                            //}
                            Console.WriteLine("Inserisci numero di telefono di {0}. Il prefisso è +39", nomeCognome[telefoni]);
                            telefono[telefoni] = Console.ReadLine();
                            while (telefono[telefoni].Length != 10)
                            {
                                Console.WriteLine("Un numero di telefono deve avere 10 cifre");
                                telefono[telefoni] = Console.ReadLine();
                            }
                            telefoni++;
                        }
                        if (telefoni == nomiMax)
                        {
                            Console.WriteLine("L'elenco è pieno");
                            Console.ReadLine();
                        }
                        break;
                    case 2:
                        if (telefoni != 0)
                        {
                            for (int i = 0; i < telefoni; i++)
                            {
                                Console.WriteLine("Il numero di telefono di {0} è: {1}", nomeCognome[i], telefono[i]);
                            }
                        }
                        else
                        {
                            Console.WriteLine("Non hai inserito nessun numero di telefono");
                        }
                        Console.WriteLine("Premere invio per continuare");
                        Console.ReadLine();
                        break;
                }
            } while (opzione != 0);
        }
    }
}
