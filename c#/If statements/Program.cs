bool isMale = true;
bool isTall = true;

// && and
// || or
if(isMale && isTall)
{
    System.Console.WriteLine("you are a tall male");
    
}
// ! mean not
else if(isMale && !isTall)
{
    System.Console.WriteLine("You are a short male");
}
else if(!isMale && isTall)
{
    System.Console.WriteLine("You are tall but not male");
}
else
{
    System.Console.WriteLine("you are not male and not tall");
}

Console.ReadLine();