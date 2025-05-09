    public int RomanToInt(string s) {
                int Number = 0;

        string[] UniqSymbols = { "IV", "IX", "XL", "XC", "CD", "CM" };
        int[] UniqValues = { 4, 9, 40, 90, 400, 900 };

        for (int i = 0; i < UniqSymbols.Length; i++)
        {
            while (s.Contains(UniqSymbols[i])) 
            {
                int index = s.IndexOf(UniqSymbols[i]); 

                Number += UniqValues[i];
                s = s.Remove(index, 2);

            }
        }


        char[] Symbols = {'I','V', 'X', 'L', 'C', 'D', 'M'};
        int[] Values = {1, 5, 10, 50, 100, 500, 1000};

        for (int i = 0; i < s.Length; i++)
        {
            int index = Array.IndexOf(Symbols, s[i]);
            if (index != -1)
            {
                Number += Values[index];
            }
        }

        return Number;
    }

