using System;

namespace Common_operators_in_Csharppp
{
    class Program
    {
        static void Main()
        {
            //int Numerator = 10;
            //int Denumerator = 2;

            //int Result = Numerator / Denumerator;

            //Console.WriteLine("Result = {0}", Result);

            int Number = 10;

            bool IsNumber10 = Number == 10 ? true: false;

            //if(Number == 10)
            //{
            //    IsNumber10 = true;
            //}
            //else
            //{
            //    IsNumber10 = false;
            //}

            //Console.WriteLine("Number == 10 is {0}", IsNumber10);

            //NULLABLE TYPES ?????

            //int j = null;  nop

            bool? j = null;

            switch (j)
            {
                case true:
                    Console.WriteLine("Is true");
                    break;

                case false:
                    Console.WriteLine("Is false");
                    break;

                case null:
                    Console.WriteLine("Is null");
                    break;
            }

            //int? TicketsOnSale = null;

            //int AvailableTickets = TicketsOnSale ?? 0; daca este null, atribuie o valoarea aleasa de utilizator altfel valoarea implicita a variabilei verificate

            //Console.WriteLine("Tickets on sale = {0}", AvailableTickets);
        }
    }
}
