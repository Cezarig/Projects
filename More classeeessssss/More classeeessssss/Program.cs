using System;

class Circle
{
    float m_pi = 3.141F;
    int m_radius;

    public Circle(int Radius)
    {
        m_radius = Radius;
    }

    public float Area()
    {
        return m_pi * m_radius * m_radius;
    }
}

namespace More_classeeessssss
{
    class Program
    {
        static void Main()
        {
            Circle c1 = new Circle(7);

            Console.Write(c1.Area());
        }
    }
}
