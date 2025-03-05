#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

enum enCharType {SmallLetter = 1, CapitalLetter = 2, SpecialChararcter = 3, Digit = 4};

float ReadKey(string Msg)
{
    int Key = 0;
    do
    {
        cout << Msg;
        cin >> Key;
    } while (Key <= 0);

    return Key;   
}

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
    return char(RandomNumber(48,57));
}

string GenerateWord(enCharType CharType , short Length)
{
    string Word;

    for (int i = 1; i <= Length ; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
        
    }

    return Word;
}

string GenerateKey()
{
    string Key = "";

    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
    return Key;

}

void FillArrayWhithKeys(string arr[100] ,short arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = GenerateKey();
    }
    
}

void PrintKeysofArray(string arr[100],short arrLength)
{
    cout << "\nArray elements : \n\n";
    for (int i = 0; i < arrLength; i++)
        cout << "Array[" << i << "] : " << arr[i] << endl;

    cout << endl;    
}

int main()
{
    srand((unsigned)time(NULL));
    
    string arr[100];
    int arrLength = ReadKey("Please Enter How Maney Key You Want : ");
    
    FillArrayWhithKeys(arr, arrLength);

    PrintKeysofArray(arr, arrLength);
    
    return 0;
}