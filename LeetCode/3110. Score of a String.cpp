
    int scoreOfString(string s) 
    {
 int v[20];
    int rs=0;
    for (int i = 0;i < s.length();i++) {

        v[i] = (int)(s[i]);
    }

    for (int i = 1;i <s.length();i++) {

        rs += abs(v[i-1] - v[i]);
    }

    return rs;
    }
