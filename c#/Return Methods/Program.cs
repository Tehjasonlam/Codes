
int cubenum = cube(5);
System.Console.WriteLine(cubenum);
System.Console.WriteLine(cube(5));
Console.ReadLine();

// int is what being returned in method
static int cube(int num)
{
    int result = num * num * num;
    return result;
}