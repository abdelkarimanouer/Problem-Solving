using System.Text.RegularExpressions;

    public bool IsPalindrome(string s) {
        s = s.ToLower();
        s = Regex.Replace(s, @"[^a-zA-Z0-9]", "");
        
        char[] chars = s.ToCharArray();
        Array.Reverse(chars);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < chars.Length; i++)
        {
            sb.Append(chars[i]);
        }

        if (s == sb.ToString())
        {
            return true;
        }

        return false;
    }