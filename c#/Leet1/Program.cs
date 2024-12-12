Console.WriteLine("Enter A string of English Letters");
        string s = Console.ReadLine();
        bool[] uppercase = new bool[26];
        bool[] lowercase = new bool[26];
        char[] arr = s.ToCharArray();
        for (int i = 0; i < arr.Length; i++)
        {
            char c = arr[i];
            if (char.IsLower(c))
            {
                lowercase = true;
            }
 
            if (char.IsUpper(c))
            {
             uppercase = true;
            }
        }