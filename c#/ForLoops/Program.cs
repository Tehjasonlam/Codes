for (int i = 0; i < 10; i++) 
{
  if (i == 4) 
  {
    continue;
;
  }
  Console.WriteLine(i);
}

//Loop through the elements in the cars array using the foreach loop
string[] cars = {"Volvo", "BMW", "Ford", "Mazda"};
foreach (string i in cars) 
{
  Console.WriteLine(i);
}

//SORTS THE ARRAY A-Z
Array.Sort(cars);
foreach (string i in cars)
{
  Console.WriteLine(i);
} 