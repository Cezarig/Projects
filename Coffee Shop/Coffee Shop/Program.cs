using System;


namespace Coffee_Shop
{
    class Program
    {
        
        static void Choice(ref string choice, ref int TotalSum){

            Console.WriteLine("What do you want to choose ? ");
            Console.WriteLine("Total sum : {0}. ", TotalSum);
            Console.WriteLine("1 - Small coffee, 2 - Medium Coffee, 3 - Big coffee, 4 - Quit order");
            choice = Console.ReadLine();
        }

        static void Main()
        {
            Console.ForegroundColor = ConsoleColor.Blue;
            string choice = "0";
            int TotalSum = 0;
            Choice(ref choice, ref TotalSum);
            while (choice != "4"  && choice != "Quit Order" && choice != "QUIT ORDER" && choice != "quit order"){

                switch (choice)
                {
                    case "1":
                    case "small":
                    case "Small":
                    case "SMALL":
                        TotalSum += 1;
                        Console.Clear();
                        Choice(ref choice, ref TotalSum);
                        if (choice == "4" || choice == "4" || choice == "Quit Order" || choice == "QUIT ORDER" || choice == "quit order")
                        {
                            Console.Write("Thanks for the order, total sum to pay is : {0}", TotalSum);
                        }
                        break;
                    case "2":
                    case "medium":
                    case "Medium":
                    case "MEDIUM":
                        TotalSum += 2;
                        Console.Clear();
                        Choice(ref choice, ref TotalSum);
                        if (choice == "4" || choice == "4" || choice == "Quit Order" || choice == "QUIT ORDER" || choice == "quit order")
                        {
                            Console.Write("Thanks for the order, total sum to pay is : {0}", TotalSum);
                        }
                        break;
                    case "3":
                    case "big":
                    case "Big":
                    case "BIG":
                        TotalSum += 4;
                        Console.Clear();
                        Choice(ref choice, ref TotalSum);
                        if (choice == "4" || choice == "4" || choice == "Quit Order" || choice == "QUIT ORDER" || choice == "quit order")
                        {
                            Console.Write("Thanks for the order, total sum to pay is : {0}", TotalSum);
                        }
                        break;
                    default:
                        Console.WriteLine("That's not a proper choice.");
                        choice = Console.ReadLine();
                        Choice(ref choice, ref TotalSum);
                        if (choice == "4" || choice == "4" || choice == "Quit Order" || choice == "QUIT ORDER" || choice == "quit order")
                        {
                            Console.Write("Thanks for the order, total sum to pay is : {0}", TotalSum);
                        }
                        break;
                }
            }
            if(TotalSum == 0){

                Console.Write("Thanks for the order, total sum to pay is : {0}", TotalSum);
            }
        }
    }
}
