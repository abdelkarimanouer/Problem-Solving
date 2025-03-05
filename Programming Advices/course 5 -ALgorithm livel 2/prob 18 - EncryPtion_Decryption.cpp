#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string ReadText()
{
    string Text;

    cout << "Please Enter Text : ";
    getline(cin, Text);
    
    return Text;
}

string EncryptText(string Text, short Key)
{
    for (int i = 0; i <= Text.length() ; i++)
    {
        Text[i] = char((int) Text[i] + Key);
    }
    return Text ;
}

string DecryptText(string Text, short Key)
{
    for (int i = 0; i <= Text.length() ; i++)
    {
        Text[i] = char((int) Text[i] - Key);
    }
    return Text ;    
}

// Rf_liqKmf_kkcb?`sF_bfmmb (ThanksMohammedAbuHadhoud)

int main()
{
    short Key = 2;

    string Text = ReadText();
    string AfterEncryptText = EncryptText(Text, Key);
    string AfterDecryptText = DecryptText(AfterEncryptText, Key);

    cout << "\nText Before Encryption : " << Text << endl;
    cout << "Text After Encryption : " << AfterEncryptText << endl;
    cout << "Text After decryption : " << AfterDecryptText << endl;

    return 0;
} 