using System;


//정적 변수,메소드
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

//this() 사용법
class MyClass
{
    int a, b, c;

    public MyClass()
    {
        this.a = 543;
    }
    public MyClass(int b) : this()
    {
        this.b = b;
    }
    public MyClass(int b,int c) : this(b)
    {
        this.c = c;
    }
    public void printField()
    {
        Console.WriteLine("a:{0} b:{1} c{2}", a, b, c);
    }
}
//상속
class Base
{
    protected string Name;
    public Base(string Name)
    {
        this.Name = Name;
    }
}
class Derived : Base
{
    public Derived(string Name) : base(Name)
    {
        Console.WriteLine("{0}.Derived()", this.Name);
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


        MyClass a = new MyClass();
        a.printField();

        MyClass b = new MyClass(23);
        b.printField();

        MyClass c = new MyClass(10, 20);
        c.printField();

        Derived d = new Derived("asdf");
    }
}