#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

enum enQuestionLevel {Easy = 1, Med = 2, Hard = 3, MixLevel = 4};
enum enOperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOperation = 5};

string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add :
        return "+";
        break;
    case enOperationType::Sub :
        return "-";
        break;
    case enOperationType::Mul :
        return "x";
        break;
    case enOperationType::Div :
        return "/";
        break;                    
    default:
        return "MixOperation";
        break;
    }
}

string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = {"Easy", "Med", "Hard", "Mix"};
    return arrQuestionLevelText[QuestionLevel - 1];
}

int RandomNumber(int From, int To) 
{   
    int randNum = rand() % (To - From + 1) + From; 

    return randNum; 
} 

void SetScreenColor(bool Right)
{
    if (Right)
    {
        system("color 2F");
    }
    else
    {
        system("color 4F");
        cout << "\a";
    }   
    
}

short ReadHowManyQuestion()
{
    short NumberOfQuestion;
    do
    {
        cout << "How many Question do you want to answer ? ";
        cin >> NumberOfQuestion;
    } while (NumberOfQuestion < 1 || NumberOfQuestion > 10);
    return NumberOfQuestion;
}

enQuestionLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;
    do
    {
        cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix : ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuestionLevel) QuestionLevel;
}

enOperationType ReadOpType()
{
    short OpType = 0;
    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix : ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);

    return (enOperationType) OpType;    
}

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestion;
    enQuestionLevel QuestionLevel;
    enOperationType OpType;
    short NumberOfWrongAnswer = 0;
    short NumberOfRightAnswer = 0;
    bool IsPass = false;
};

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add :
        return Number1 + Number2;
    case enOperationType::Sub :
        return Number1 - Number2;
    case enOperationType::Mul :
        return Number1 * Number2;
    case enOperationType::Div :
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

enOperationType GetRandomOperation()
{
    int Op = RandomNumber(1,4);
    return (enOperationType) Op;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionLevel::MixLevel)
    {
        QuestionLevel = (enQuestionLevel) RandomNumber(1,3);
    }
    if (OpType == enOperationType::MixOperation)
    {
        OpType = GetRandomOperation();
    }
    Question.OperationType = OpType;

    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy :
        Question.Number1 = RandomNumber(1,10);
        Question.Number2 = RandomNumber(1,10);
    
        Question.CorrectAnswer= SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);

        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionLevel::Med :
        Question.Number1 = RandomNumber(10,50);
        Question.Number2 = RandomNumber(10,50);
    
        Question.CorrectAnswer= SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);

        Question.QuestionLevel = QuestionLevel;
        return Question;
    case enQuestionLevel::Hard :
        Question.Number1 = RandomNumber(50,100);
        Question.Number2 = RandomNumber(50,100);
    
        Question.CorrectAnswer= SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);

        Question.QuestionLevel = QuestionLevel;
        return Question;
    }
    return Question;
       
}

void GenerateQuizzQuestion(stQuizz& Quizz)
{
    for (int Question = 0; Question < Quizz.NumberOfQuestion; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OpType);
    }

}

int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "\n";
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestion << "] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n_________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswer++;

        cout << "Wrong Answer :( \n";
        cout << "The Right Answer is: ";
        cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
        cout << "\n";
    }
    else
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswer++;

        cout << "Right Answer :) \n";
    }
    cout << endl;

    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswer(stQuizz& Quizz)
{
    for (int QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);

        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.IsPass = (Quizz.NumberOfRightAnswer >= Quizz.NumberOfWrongAnswer);
}

string GetFinalResultsText(bool Pass)
{
    if (Pass)
        return "Pass :)";
    else
       return "Fail :(";    
}

void PrintQuizzResults(stQuizz Quizz)
{
    cout << "\n";
    cout << "___________________________________________\n\n";
    cout << "Final Results is " << GetFinalResultsText(Quizz.IsPass);
    cout << "\n___________________________________________\n\n";

    cout << "Number Of Questions    :" << Quizz.NumberOfQuestion << endl;
    cout << "Question Level         :" << GetQuestionLevelText(Quizz.QuestionLevel) << endl; 
    cout << "OpType                 :" << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number of Right Answer :" << Quizz.NumberOfRightAnswer << endl;
    cout << "Number of Wrong Answer :" << Quizz.NumberOfWrongAnswer << endl;

    cout << "___________________________________________\n";

}

void PlayMathGame()
{
    stQuizz Quizz;

    Quizz.NumberOfQuestion = ReadHowManyQuestion();
    Quizz.QuestionLevel = ReadQuestionLevel();
    Quizz.OpType = ReadOpType();

    GenerateQuizzQuestion(Quizz);
    AskAndCorrectQuestionListAnswer(Quizz);
    PrintQuizzResults(Quizz);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    
    do
    {
        ResetScreen();
        PlayMathGame();

        cout << endl << "Do You want to play again ? Y/N :";
        cin >> PlayAgain;
        
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    cout << endl;

    return 0;
}
