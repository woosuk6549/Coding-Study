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
        public static void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        public static void Divide(int a,int b,out int quotient,out int remainder)
        {
            quotient = a / b;
            remainder = a % b;
        }
        static int Sum(params int[] args)
        {
            int sum = 0;
            for(int i = 0; i < args.Length; ++i)
            {
                if (i > 0) Console.Write(", ");
                Console.Write(args[i]);
                sum += args[i];
            }
            Console.WriteLine();
            return sum;
        }
        public static void Main()
        {
            int result = Calculator.Plus(10, 23);
            Console.WriteLine(result);

            result = Calculator.Minus(100, 32);
            Console.WriteLine(result);

            int x = 3, y = 4;
            Console.WriteLine("x: {0}, y: {1}", x, y);
            Swap(ref x, ref y);
            Console.WriteLine("x: {0}, Y: {1}", x, y);

            int quo=0, rem=0;
            int a = 30, b = 7;
            Divide(a, b, out quo, out rem);
            Console.WriteLine("{0},{1}", quo, rem);

            int sum = Sum(3, 4, 5, 6, 7, 8, 9);
            Console.WriteLine(sum);
        }
    }
}