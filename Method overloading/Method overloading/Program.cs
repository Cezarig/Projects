using System;

namespace Method_overloading
{
    class Program
    {
        static void Main()
        {
             //Add()
        }
        public static void Add(int fn, int sn, params int[] TN)
        {
            Console.WriteLine("Sum = {0}", fn + sn);
        }

        public static void Add(int fn, int sn,int[] TN)
        {
            Console.WriteLine("Sum = {0}", fn + sn);
        }

        //public static int  Add(int fn, int sn, int tn)
        //{
        //    Console.WriteLine("Sum = {0}", fn + sn + tn); ---- eroare de compilare, nu poti definii 2 functii diferentiate de tipul returnat
        //    return fn + sn + tn;
        //}

        //public static void Add(float fn, float sn, out int sn)
        //{
        //    Console.WriteLine("Sum = {0}", fn + sn);
        //}

        //public static void Add(float fn, int sn)
        //{
        //    Console.WriteLine("Sum = {0}", fn + sn);
        //}
    }
}
