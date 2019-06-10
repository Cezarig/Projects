using System;

public class Employee
{
    public string m_FirstName = "FN";
    public string m_LastName = "LN";

    public virtual void PrintFullName()
    {
        Console.WriteLine(m_FirstName + " " + m_LastName);
    }
}

public class PartTimeEmployee : Employee
{
    public override void PrintFullName()
    {
        Console.WriteLine(m_FirstName + " " + m_LastName + " - Part Time");
    }
}

public class FullTimeEmployee : Employee
{
    public override void PrintFullName()
    {
        Console.WriteLine(m_FirstName + " " + m_LastName + " - Full Time");
    }
}

public class TemporaryEmployee : Employee
{
    public override void PrintFullName()
    {
        Console.WriteLine(m_FirstName + " " + m_LastName + " - Temporary");
    }
}

namespace Polymorphism
{
    class Program
    {
        static void Main()
        {
            //Employee E = new Employee();
            //E.PrintFullName();

            Employee[] employees = new Employee[4];

            employees[0] = new Employee();
            employees[1] = new PartTimeEmployee();
            employees[2] = new FullTimeEmployee();
            employees[3] = new TemporaryEmployee();

            foreach(Employee e in employees)
            {
                e.PrintFullName();
            }
        }
    }
}
