using System;

namespace Conversii_blana_in_C_sharpp
{
    class Program
    {
        static void Main()
        {
            float f = 123.16F;

            int i = (int)f;

            Console.WriteLine(i);

            //SAAAAAAAAUUUUUUUU

            i = Convert.ToInt32(f);

            Console.WriteLine("\n{0}", i);

            string StrNumber = "100gy";

            //int result = int.Parse(StrNumber);  that boyo converts the shit out of that string

            int Result = 0;

            bool verify = int.TryParse(StrNumber, out Result);

            if (verify)
            {
                Console.WriteLine("\n{0}", i);
            }
            else
            {
                Console.WriteLine("\nAnother one, boy");
            }

        }
    }
}
