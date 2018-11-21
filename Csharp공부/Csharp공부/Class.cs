using System;

class Global
{
    public static int count = 0;
}
class ClassA
{
    public ClassA()
    {
        Global.count++;
    }
}
class ClassB
{
    public ClassB()
    {
        Global.count++;
    }
}

class MainApp
{
    static void Main()
    {
        Console.WriteLine("Global count : {0}", Global.count);

        new ClassA();
        new ClassB();
        new ClassB();
        new ClassA();

        Console.WriteLine("Global count : {0}", Global.count);

    }
}