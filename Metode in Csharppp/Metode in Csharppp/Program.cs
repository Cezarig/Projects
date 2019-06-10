using System;

namespace Metode_in_Csharppp
{
    class Program
    {
        public static void Main()
        {
            //Program p = new Program();          - daca metoda nu este statica 
            //p.EvenNumbers(ce vrei tu);

            //Program.EvenNumbers(ce vrei tu);              - daca metoda este statica

            Program p = new Program();
            int sum = p.Add(10, 20);

            Console.Write("{0}", sum);
        }

        public int Add(int FN, int SN)
        {
            return FN + SN;
        }

        public static void EvenNumbers(int target)
        {
            int start = 0;

            while(start <= target)
            {
                Console.Write("{0} ", start);
                start += 2;
            }
        }
    }
}
