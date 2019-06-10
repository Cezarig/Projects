using System;

namespace Tipuri_de_metode_in_Csharpp
{
    class Program
    {
        static void Main(string[] args)
        {
            //int i = 0;

            //SimpleMethod(ref i);

            //Console.Write("{0}", i);

            //Calculate(10, 20, out int Total, out int Product);

            //Console.Write("Sum = {0} , Product = {1}", Total, Product);

            int[] Numbers = new int[3];

            Numbers[0] = 101;
            Numbers[1] = 102;
            Numbers[2] = 103;

            //ParamsMethod();
            //ParamsMethod(Numbers);                    - tipuri de apelare al metodelor care contin params
            //ParamsMethod(101, 102, 103, 104, 105);
        }

        public static void Calculate(int FN, int LN, out int Sum, out int Product)
        {
            Sum = FN + LN;
            Product = FN * LN;
        }

        public static void SimpleMethod(ref int j)
        {
            j = 101;
        }

        //ARRAYS !!!!!!!!!!!!!!!!!!!

        public static void ParamsMethod(params int[] Numbers)
        {
            Console.Write("There are {0} elements in array.\n", Numbers.Length);

            foreach(int i in Numbers)
            {
                Console.Write("{0} ", i);
            }

            Console.Write("\n\n");
        }

    }
}
