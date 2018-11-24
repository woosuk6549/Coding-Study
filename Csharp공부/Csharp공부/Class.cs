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
//is,as
class Mammal
{
    public void Nurse()
    {
        Console.WriteLine("Nurse()");
    }
}
class Dog : Mammal
{
    public void Bark()
    {
        Console.WriteLine("Bark()");
    }
}
class Cat : Mammal
{
    public void Meow()
    {
        Console.WriteLine("Meow()");
    }
}

//오버라이딩
class ArmorSuite {
    public virtual void Initialize()
    {
        Console.WriteLine("Armored");
    }
}
class Ironman : ArmorSuite
{
    public override void Initialize()
    {
        base.Initialize();
        Console.WriteLine("repulsor rays armored");
    }
}

class Base2
{
    public void MyMethod()
    {
        Console.WriteLine("Base.mymethod()");
    }
}
class Derived2 : Base2
{
    public new void MyMethod()
    {
        Console.WriteLine("Derived.mymethod()");
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


        Mammal mammal = new Dog();
        Dog dog;

        if(mammal is Dog)
        {
            dog = (Dog)mammal;
            dog.Bark();
        }

        Mammal mammal2 = new Cat();
        Cat cat = mammal2 as Cat;
        if (cat != null)
            cat.Meow();

        Cat cat2 = mammal as Cat;
        if (cat2 != null)
            cat2.Meow();
        else
            Console.WriteLine("cat2 is not a  cat");
    }
}