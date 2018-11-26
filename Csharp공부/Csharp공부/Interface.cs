using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Csharp공부
{
    interface ILogger
    {
        void writeLog(string message);
    }
    class ConsoleLogger : ILogger
    {
        public void writeLog(string message)
        {
            Console.WriteLine("{0} {1}", DateTime.Now.ToLocalTime(), message);
        }
    }
    class FileLogger : ILogger
    {
        private StreamWriter writer;
        public FileLogger(string path)
        {
            writer = File.CreateText(path);
            writer.AutoFlush = true;
        }
        public void writeLog(string message)
        {
            writer.WriteLine("{0} {1}", DateTime.Now.ToShortTimeString(), message);
        }
    }
    class ClimateMonitor
    {
        private ILogger logger;
        public ClimateMonitor(ILogger logger)
        {
            this.logger = logger;
        }
        public void start()
        {
            while (true)
            {
                Console.Write("온도 입력 :");
                string temperature = Console.ReadLine();
                if (temperature == "")
                    break;
                logger.writeLog("현재 온도:" + temperature);
            }
        }
    }

    //인터페이스 다중상속
    interface IRunnable
    {
        void Run();
    }
    interface IFlyable
    {
        void Fly();
    }
    class FlyingCar : IRunnable, IFlyable
    {
        public void Run()
        {
            Console.WriteLine("Run");
        }
        public void Fly()
        {
            Console.WriteLine("Fly");
        }
    }

    //추상클래스:인스턴스를 가지지 못함
    abstract class AbstactBase
    {
        protected void PrivateMethodA()
        {
            Console.WriteLine("Abstractbase.privatemethodA");
        }
        public void PublicMethodA()
        {
            Console.WriteLine("Abstarctbase.publicmethodA");
        }
        public abstract void AbstarctMethodA();
    }
    class Derived : AbstactBase
    {
        public override void AbstarctMethodA()
        {
            Console.WriteLine("Derived.abstarctmethod");
            PrivateMethodA();
        }
    }
    class Interface
    {
        static void Main(string[] args)
        {
            ClimateMonitor monitor = new ClimateMonitor(new FileLogger("MyLog.txt"));
            monitor.start();

            FlyingCar car = new FlyingCar();
            car.Run();
            car.Fly();

            IRunnable runnable = car as IRunnable;
            runnable.Run();

            IFlyable flyable = car as IFlyable;
            flyable.Fly();

            AbstactBase obj = new Derived();
            obj.AbstarctMethodA();
            obj.PublicMethodA();
        }
    }
}
