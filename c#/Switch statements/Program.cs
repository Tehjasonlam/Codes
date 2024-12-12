// See https://aka.ms/new-console-template for more information

System.Console.WriteLine("Enter a Day Number");
int dayNum = Convert.ToInt32(Console.ReadLine());
Console.WriteLine(Getday(dayNum));

static string Getday(int dayNum)
{
    string dayName;

    switch(dayNum)
    {
        case 0:
            dayName = "Sunday";
            break;
        case 1:
            dayName = "Monday";
            break;
        case 2:
            dayName = "Tuesday";
            break;
        case 3:
            dayName = "Wednesday";
            break;
        case 4:
            dayName = "Thursday";
            break;
        case 5:
            dayName = "Friday";
            break;
        case 6:
            dayName = "Saturday";
            break;
        default:
            dayName =  "Invalid Day Number";
            break;

    }

    return dayName;

}
