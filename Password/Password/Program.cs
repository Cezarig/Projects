using System;
using CryptSharp;

namespace Password
{
    class Program
    {
        static void Main(string[] args)
        {
            string CryptedPassword = Crypter.MD5.Crypt("Bcrypt"), TryPass;
            Console.WriteLine("Type your password :");

            TryPass = Console.ReadLine();

            if(Crypter.CheckPassword(TryPass, CryptedPassword))
            {
                Console.Write("Unlocked");
            }
            else
            {
                Console.Write("Locked");
            }

        }
    }
}
