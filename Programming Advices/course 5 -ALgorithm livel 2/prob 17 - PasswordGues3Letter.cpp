#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string ReadPassword()
{
    string Password = "";

        cout << "Please Enter A Password Guess a 3 letter (ALL Capital) : " ;
        cin >> Password;

    return Password;   
}

bool PasswordGuess3Letter(string Password)
{  
    string word = "";
    int counter = 0;

    for (int i = 65; i <= 90; i++)
    {

        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                counter++;
                cout << "Trial[" << counter << "] : " << word << endl;

                if (word == Password)
                {
                    cout << "Your Password Is : " << word << endl;
                    cout << "Found Your Password After [" << counter << "] Trials. \n" ;
                    return true;
                }
                
                word = ""; 
            }                      
        }
    }
    return false;    
}

int main()
{ 

    if ( PasswordGuess3Letter(ReadPassword()) == true )
        cout << "\nWelcome In Your Page :)" << endl;
    else
        cout << "\nOOPS! Try Again." << endl;    

    return 0;
}