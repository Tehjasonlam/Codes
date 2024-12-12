using System;
using IntroLibrary;

namespace IntroUI
{
    class Program
    {
         static void Main(string[] args)
        {
            PersonModel p = new PersonModel
            {
                FirstName = "Jason",
                Lastname = " Lam"
            };
            System.Console.WriteLine($"{p.FirstName}{p.Lastname} is my name");

            Console.WriteLine("Hello, World!");
            Console.WriteLine("This is a test");
        }
    }
}
