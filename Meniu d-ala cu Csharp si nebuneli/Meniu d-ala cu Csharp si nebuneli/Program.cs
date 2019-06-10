using System;

namespace Meniu_d_ala_cu_Csharp_si_nebuneli
{
    class Program
    {
        static void Main()
        {
            int SumCheckout = 0;

            Start:

            Console.Clear();

            Console.WriteLine("Boyo, ai de ales intre 3 chestii : \n1 - Pileala d-aia buna = 50 dinero\n2 - Los espíritus mexicanos = 30 dinero \n3 - Taco = 3 dinero");
            int Choice = int.Parse(Console.ReadLine());

            switch (Choice)
            {
                case 1:
                    SumCheckout += 50;
                    break;

                case 2:
                    SumCheckout += 30;
                    break;

                case 3:
                    SumCheckout += 3;
                    break;

                default:
                    Console.WriteLine("\nNo es bueno, {0}.", Choice);
                    break;
            }

        Decide:
            Console.WriteLine("\nOrdenas algo ? Sí or No.");
            string UserDecision = Console.ReadLine();

            switch (UserDecision.ToLower())
            {
                case "si":
                    goto Start;
                case "no" :
                    break;
                default:
                    Console.WriteLine("\nNo es bueno, alege Sí sau No.");
                    goto Decide; 
            }

            Console.WriteLine("\nSee ya later, hermano. Lasa si tu {0} dinero la fraternidad.", SumCheckout);
        }
    }
}
