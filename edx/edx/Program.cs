using System;

namespace edx
{
    class Program
    {
        static void Main(string[] args)
        {
            string FirstName = "Tom";
            string LastName = "Thumb";
            int age = 18;
            string street = "123 Fourth Street";
            string city = "Anytown";
            string country = "MyCountry";
            DateTime birthDate = new DateTime(1932, 6, 1);

            Console.WriteLine("{0} age is {1}, birthed on {2} and lives on the street {3}, city {4}, country {5}", FirstName + LastName, age, birthDate,  street, city, country);
        }
    }
}
