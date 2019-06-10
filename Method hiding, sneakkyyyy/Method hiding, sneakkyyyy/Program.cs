using System;

public class Employee
{
    public string m_FirstName;
    public string m_LastName;

    public void PrintName()
    {
        Console.WriteLine(m_FirstName + " " + m_LastName);
    }
}

public class PartTimeEmployee : Employee
{
    // Se foloseste " new " pentru a schimba metoda mostenita din clasa "parinte". Ii misto
    // Daca vrei sa revii la metoda anteriorare, te folosesti de "base" pentru a apela metoda din clasa "parinte". Yayyy
    public new void PrintName()
    {
        //base.PrintName();------BASE
        Console.WriteLine(m_FirstName + " " + m_LastName + " - Contractor"); //----NEW
    }
}

public class FullTimeEmployee : Employee
{

}

namespace Method_hiding__sneakkyyyy
{
    class Program
    {
        static void Main(string[] args)
        {
            FullTimeEmployee FTE = new FullTimeEmployee();
            FTE.m_FirstName = "FullTime";
            FTE.m_LastName = "Employee";
            FTE.PrintName();

            Employee PTE = new PartTimeEmployee(); // Daca declari obiectul ca fiind de tipul clasei 
                                                   // principale dar foloseste noul tip de date mostenit
                                                   // prin intermediul clasei "parinte", aceasta va mosteni 
                                                   // toate caracteristicile clasei principale.
            PTE.m_FirstName = "PartTime";
            PTE.m_LastName = "Employee";
            //((Employee)PTE).PrintName(); // - castare la clasa principala
            PTE.PrintName(); 
        }
    }
}
