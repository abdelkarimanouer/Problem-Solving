#include <iostream>
#include <ctime>
using namespace std; 
 
enum enCharType {SmallLetter = 1, CapitalLetter = 2, SpecialChararcter = 3, Digit = 4};


int RandomNumber(int From, int To) 
{   
int randNum = rand() % (To - From + 1) + From; 

return randNum; 
} 
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter :
        return char(RandomNumber(97,122));
        break;
    case enCharType::CapitalLetter :
        return char(RandomNumber(65,90)) ;
        break;        
    case enCharType::SpecialChararcter :
        return char(RandomNumber(33,47)) ;
        break;
    case enCharType::Digit :
        return char(RandomNumber(48,57)) ;
        break;
    }
    return char(RandomNumber(48,57)); // If user inter Other Type;
}


int main() 
{     
    srand((unsigned)time(NULL)); 

    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;    
    cout << GetRandomCharacter(enCharType::SpecialChararcter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;    
    return 0; 
 
}