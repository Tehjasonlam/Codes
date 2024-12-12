// See https://aka.ms/new-console-template for more information
string phrase = "Diane Academy";
char Grade = 'A';
int age = 20;
double gpa = 4.0;
bool isFemale = true;


// strings
System.Console.WriteLine(phrase.Length);
// Length of phrase
System.Console.WriteLine(phrase[3]); 
// what let at the index
System.Console.WriteLine(phrase.IndexOf("Academy")); 
// Where Academy starts
System.Console.WriteLine(phrase.Substring(3,2));
// Grab the letter at the starting index and how many index after

// numbers
System.Console.WriteLine( 5 + 8 );
// add
System.Console.WriteLine( 5 % 2 );
// mod gives remainder 
System.Console.WriteLine( 4 + 2 * 3);
// pemdas
System.Console.WriteLine( 5 / 2.0 );
// how to get a double back

int num = 6;
num++;
// add 1 to the number
System.Console.WriteLine( num );

int num2 = 6;
num2--;
// sub 1 to the number
System.Console.WriteLine( num2 );

System.Console.WriteLine(Math.Abs(-40));
// abs
System.Console.WriteLine(Math.Pow(3,2));
// exponent 
System.Console.WriteLine(Math.Sqrt(4));
// squareroot
System.Console.WriteLine(Math.Max(4 , 90));
// give biggest number
System.Console.WriteLine(Math.Min(4 , 90));
// give smallest number
System.Console.WriteLine(Math.Round(4.6));
// round the numbers

Console.ReadLine();