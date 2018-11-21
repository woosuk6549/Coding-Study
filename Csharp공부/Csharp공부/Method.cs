using System;
namespace Method
{
    class Calculator
    {
        public static int Plus(int a,int b)
        {
            return a + b;
        }
        public static int Minus(int a,int b)
        {
            return a - b;
        }
    }
    class MainApp
    {
        public static void Main()
        {
            int result = Calculator.Plus(10, 23);
            Console.WriteLine(result);

            result = Calculator.Minus(100, 32);
            Console.WriteLine(result);
        }
    }
}