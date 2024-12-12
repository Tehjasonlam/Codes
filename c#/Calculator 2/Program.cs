//main

Console.Write("Enter a number: ");
double num1 = Convert.ToDouble(Console.ReadLine());

Console.Write("enter Operator: ");
string op = Console.ReadLine();

Console.Write("Enter a number: ");
double num2 = Convert.ToDouble(Console.ReadLine());

if(op == "+")
{
    Console.WriteLine(num1 + num2);
}
else if(op == "-")
{
    Console.WriteLine(num1 - num2);
}
else if(op == "*")
{
    Console.WriteLine(num1 * num2);
}
else if(op == "/")
{
    Console.WriteLine(num1 / num2);
}
else
{
    Console.WriteLine("invalid Opporator");
}

