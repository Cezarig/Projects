using System;

namespace Read_and_Write
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Please enter your first name : ");

            string FirstName = Console.ReadLine();

            Console.WriteLine("\nPlease enter your last name : ");

            string LastName = Console.ReadLine();

            //Console.WriteLine("Hello " + Username);   Write with CONCATENATION !!!

            /*Console.WriteLine("\nHello {0}", Username);  Write with PLACEHOLDER !!!*/

            Console.WriteLine("\nHello {0}, {1}", FirstName, LastName);
        }
    }
}
