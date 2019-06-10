using System;

public class Employee
{
    public string m_firstname;
    public string m_lastname;
    public string m_email;

    public Employee()
    {
        Console.WriteLine("Employee");
    }

    public Employee(string Message)
    {
        Console.WriteLine(Message);
    }

    public void About()
    {
        Console.WriteLine("Firstname : {0}", m_firstname);
        Console.WriteLine("Lastname : {0}", m_lastname);
        Console.WriteLine("Email : {0}", m_email);
    }
}

public class FullTimeEmployee : Employee
{
    public float m_yearlysalary;
    
    public FullTimeEmployee() : base( "Derived class controling ") 
        //Controleaza pe care constructor il folosim in clasa mostenita
    {
        Console.WriteLine("FullTimeEmployee");
    }
}

public class PartTimeEmployee : Employee
{
    public float m_hourlyrate;
}


namespace Inheritanceeee
{
    class Program
    {
        static void Main()
        {
            FullTimeEmployee FTE = new FullTimeEmployee();
            FTE.m_firstname = "Cezar";
            FTE.m_lastname = "Ghiuleanu";
            FTE.About();
         
        }
    }
}
