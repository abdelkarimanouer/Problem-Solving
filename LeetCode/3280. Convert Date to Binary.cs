using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;

class Program
{
    public static string ConvertDateToBinary(string date)
    {
        if (string.IsNullOrWhiteSpace(date))
        {
            return string.Empty;
        }

        StringBuilder binary = new StringBuilder();

        List<string> parts = new List<string>( date.Split('-') );

        for (int i = 0; i < parts.Count; i++)
        {
            int number = int.Parse(parts[i]);
            binary.Append(Convert.ToString(number, 2));

            if (i < parts.Count - 1)
            {
                binary.Append("-");
            }
        }

        return binary.ToString();
    }

    static void Main()
    {
        string date = "1900-01-01";

       Console.WriteLine(ConvertDateToBinary(date));
    }
}

