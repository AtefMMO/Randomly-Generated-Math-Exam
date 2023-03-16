

#include <iostream>
#include <cstdlib>
#include <array>
#include <string>
using namespace std;
int  Multiplication(int num1, int num2) {
   //multiplay two numbers
    return num1 * num2;
}
int  Addition(int num1, int num2) {
    //adds two number
    return num1 + num2;
}
int  Subtraction(int num1, int num2) {
   //subtract two numbers
    return num1 - num2;
}
int  Division(int num1, int num2) {
   //divides two numbers
    return num1 / num2;
}
enum enLevel {
    //enum for the four choices of the game levle;
   Easy = 1, Medium = 2, Hard = 3, MixLevel = 4
};
enum enType {
    //enum for the five choices of the game type;
    addition = 1, subtraction = 2, multiplication = 3, division = 4 , MixType=5
};
int  RandomNumber(int from, int to) {
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}
int  EasyRandomNumber() {
    //returns a random number btw 1 and 10
    int RandNum = RandomNumber(1, 10);
    return RandNum;
}
int  MediumRandomNumber() {
    //returns a random number btw 25 and 50
    int RandNum = RandomNumber(25, 50);
    return RandNum;
}
int  HardRandomNumber() {
    //returns a random number btw 50 and 100
    int RandNum = RandomNumber(50, 100);
    return RandNum;
}
int  MixRandomNumber() {
    //return a random number between 3 difficulties easy med hard
    int choice = RandomNumber(1, 3);
    int RandNum = 0;
    if (choice == 1) {
       RandNum = EasyRandomNumber();
    }
    else if (choice == 2) {
        RandNum = MediumRandomNumber();
    }
    else if (choice == 3) {
        RandNum = HardRandomNumber();
    }
    return RandNum;
}
int  ValidateNumberType(int& number, string ErrorMessage) {
    //validates that the user doesnot enter a char or string and make him input the number again
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << ErrorMessage << endl;
    cin >> number;
    return number;
}
int  PostiveNumber(string message, string WarningMessage) {
    //return a postive number after validation not negative & only a number
    int number = 0;
    cout << message << endl;
    cin >> number;
    do {
        if (number < 0) {
            cout << WarningMessage << endl;
            cin >> number;
        }
        if (cin.fail()) {
            ValidateNumberType(number, "the key you pressed is not of the correct type");
        }
    } while (number < 0 || cin.fail());
    return number;
}
int  ValidatePostiveNumberBetweenTwoNumbers(int from,int to) {
    //returns a postive number between two numbers 
    int number = 0;
    number=PostiveNumber("please enter :","the number you added is not correct");
    if (number >= from && number <= to) {
        return number;
    }
    else {
        cout << "number out of bounds\n";
        cout << "Try Again\n";
        ValidatePostiveNumberBetweenTwoNumbers( from, to);
    }
}
bool CheckAnswer(int num1,int num2) {
    if (num1 == num2) {
        system("color 20");
        return true;
    }
    else if (num1 != num2) {
        system("color 40");
        return false;
    }
}
void AddElementToArray(int array[10], int& ArrayLength,int number) {
    array[ArrayLength] = number;
    ArrayLength++;
}
void DataCounter(  int num1, int num2,int array[10], int& ArrayLength) {
    //counts the time player loose and wins 
    
    if (CheckAnswer(num1, num2)) {
        AddElementToArray(array, ArrayLength, 1);
    }
    else {
        AddElementToArray(array, ArrayLength, 0);
    }
}
void PrintAdditionQuestion(int num1, int num2, int AnswerStudent, int AnswerComputer, int array[10], int& ArrayLength) {
   //prints  addition question and saves the data of who won and who didn't
    cout << num1 << "  +  " << num2 << " : " << endl;
    cin >> AnswerStudent;
    AnswerComputer = Addition(num1, num2);
    DataCounter(AnswerStudent, AnswerComputer, array, ArrayLength);
}
void PrintSubtractionQuestion(int num1, int num2, int AnswerStudent, int AnswerComputer,int array[10], int& ArrayLength) {
    //prints  subtraction question and saves the data of who won and who didn't
    cout << num1 << "  -  " << num2 << " : " << endl;
    cin >> AnswerStudent;
    AnswerComputer = Subtraction(num1, num2);
    DataCounter(AnswerStudent, AnswerComputer,array,ArrayLength);
}
void PrintMultiplicationQuestion(int num1, int num2, int AnswerStudent, int AnswerComputer, int array[10], int& ArrayLength) {
    //prints  Multiplication question and saves the data of who won and who didn't
    cout << num1 << "  *  " << num2 << " : " << endl;
    cin >> AnswerStudent;
    AnswerComputer = Multiplication(num1, num2);
    DataCounter(AnswerStudent, AnswerComputer, array, ArrayLength);
}
void PrintDivisionQuestion(int num1, int num2, int AnswerStudent, int AnswerComputer, int array[10], int& ArrayLength) {
    //prints  Division question and saves the data of who won and who didn't
    cout << num1 << "  /  " << num2 << " : " << endl;
    cin >> AnswerStudent;
    AnswerComputer = Division(num1, num2);
    DataCounter(AnswerStudent, AnswerComputer, array, ArrayLength);
}
void PrintMixQuestion(int num1, int num2, int AnswerStudent, int AnswerComputer, int array[10], int& ArrayLength) {
    //prints Mix question and saves the data of who won and who didn't
    int RandNum = RandomNumber(1, 4);
    if (RandNum == 1) {
        PrintAdditionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (RandNum == 2) {
        PrintSubtractionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (RandNum == 3) {
        PrintMultiplicationQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (RandNum == 4) {
        PrintDivisionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
}
void EasyQuestion(int type, int array[10], int& ArrayLength) {
    // from 1 to 10 problems with diffrent types
    int num1 = EasyRandomNumber();
    int num2 = EasyRandomNumber();
    int AnswerStudent = 0;
    int AnswerComputer = 0;
    if (type == 1) {
        PrintAdditionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 2) {
        PrintSubtractionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 3) {
        PrintMultiplicationQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 4) {
        PrintDivisionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 5) {
        PrintMixQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
}
void MediumQuestion(int type, int array[10], int& ArrayLength) {
    // from 25 to 50 problems with diffrent types
    int num1 = MediumRandomNumber();
    int num2 = MediumRandomNumber();
    int AnswerStudent = 0;
    int AnswerComputer = 0;
    if (type == 1) {
        PrintAdditionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 2) {
        PrintSubtractionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 3) {
        PrintMultiplicationQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 4) {
        PrintDivisionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 5) {
        PrintMixQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
}
void HardQuestion(int type, int array[10], int& ArrayLength) {
    // from 50 to 100 problems with diffrent types
    int num1 = HardRandomNumber();
    int num2 = HardRandomNumber();
    int AnswerStudent = 0;
    int AnswerComputer = 0;
    if (type == 1) {
        PrintAdditionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 2) {
        PrintSubtractionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 3) {
        PrintMultiplicationQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 4) {
        PrintDivisionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 5) {
        PrintMixQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
}
void MixQuestion(int type, int array[10], int& ArrayLength) {
    // random problems with diffrent types
    int num1 = MixRandomNumber();
    int num2 = MixRandomNumber();
    int AnswerStudent = 0;
    int AnswerComputer = 0;
    if (type == 1) {
        PrintAdditionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 2) {
        PrintSubtractionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 3) {
        PrintMultiplicationQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 4) {
        PrintDivisionQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
    else if (type == 5) {
        PrintMixQuestion(num1, num2, AnswerStudent, AnswerComputer, array, ArrayLength);
    }
}
void PrintQuestion(enLevel UserLevel, enType QuestionType, int array[10], int& ArrayLength) {
    if (UserLevel == Easy) {
        if (QuestionType == addition) {
            EasyQuestion(1, array, ArrayLength);
        }
        else if (QuestionType == subtraction) {
            EasyQuestion(2, array, ArrayLength);
        }
        else if (QuestionType == multiplication) {
            EasyQuestion(3, array, ArrayLength);
        }
        else if (QuestionType == division) {
            EasyQuestion(4, array, ArrayLength);
        }
        else if (QuestionType == MixType) {
            EasyQuestion(5, array, ArrayLength);
        }
    }
    else if (UserLevel == Medium) {
        if (QuestionType == addition) {
            MediumQuestion(1, array, ArrayLength);
        }
        else if (QuestionType == subtraction) {
            MediumQuestion(2, array, ArrayLength);
        }
        else if (QuestionType == multiplication) {
            MediumQuestion(3, array, ArrayLength);
        }
        else if (QuestionType == division) {
            MediumQuestion(4, array, ArrayLength);
        }
        else if (QuestionType == MixType) {
            MediumQuestion(5, array, ArrayLength);
        }
    }
    else if (UserLevel == Hard) {
        if (QuestionType == addition) {
            HardQuestion(1, array, ArrayLength);
        }
        else if (QuestionType == subtraction) {
            HardQuestion(2, array, ArrayLength);
        }
        else if (QuestionType == multiplication) {
            HardQuestion(3, array, ArrayLength);
        }
        else if (QuestionType == division) {
            HardQuestion(4, array, ArrayLength);
        }
        else if (QuestionType == MixType) {
            HardQuestion(5, array, ArrayLength);
        }
    }
    else if (UserLevel == MixLevel) {
        if (QuestionType == addition) {
            MixQuestion(1, array, ArrayLength);
        }
        else if (QuestionType == subtraction) {
            MixQuestion(2, array, ArrayLength);
        }
        else if (QuestionType == multiplication) {
            MixQuestion(3, array, ArrayLength);
        }
        else if (QuestionType == division) {
            MixQuestion(4, array, ArrayLength);
        }
        else if (QuestionType == MixType) {
            MixQuestion(5, array, ArrayLength);
        }
    }
}
void ExamQuestion(int ExamType, int ExamLevel, int array[10], int& ArrayLength) {
    if (ExamLevel == 1) {
        if (ExamType == 1) {
            PrintQuestion(Easy, addition, array, ArrayLength);
        }
        else if (ExamType == 2) {
            PrintQuestion(Easy, subtraction, array, ArrayLength);
        }
        else if (ExamType == 3) {
            PrintQuestion(Easy, multiplication, array, ArrayLength);
        }
        else if (ExamType == 4) {
            PrintQuestion(Easy, division, array, ArrayLength);
        }
        else {
            PrintQuestion(Easy, MixType, array, ArrayLength);
        }
    }
    else if (ExamLevel == 2) {
        if (ExamType == 1) {
            PrintQuestion(Medium, addition, array, ArrayLength);
        }
        else if (ExamType == 2) {
            PrintQuestion(Medium, subtraction, array, ArrayLength);
        }
        else if (ExamType == 3) {
            PrintQuestion(Medium, multiplication, array, ArrayLength);
        }
        else if (ExamType == 4) {
            PrintQuestion(Medium, division, array, ArrayLength);
        }
        else {
            PrintQuestion(Medium, MixType, array, ArrayLength);
        }
    }
    else if (ExamLevel == 3) {
        if (ExamType == 1) {
            PrintQuestion(Hard, addition, array, ArrayLength);
        }
        else if (ExamType == 2) {
            PrintQuestion(Hard, subtraction, array, ArrayLength);
        }
        else if (ExamType == 3) {
            PrintQuestion(Hard, multiplication, array, ArrayLength);
        }
        else if (ExamType == 4) {
            PrintQuestion(Hard, division, array, ArrayLength);
        }
        else {
            PrintQuestion(Hard, MixType, array, ArrayLength);
        }
    }
    else if (ExamLevel == 4) {
        if (ExamType == 1) {
            PrintQuestion(MixLevel, addition, array, ArrayLength);
        }
        else if (ExamType == 2) {
            PrintQuestion(MixLevel, subtraction, array, ArrayLength);
        }
        else if (ExamType == 3) {
            PrintQuestion(MixLevel, multiplication, array, ArrayLength);
        }
        else if (ExamType == 4) {
            PrintQuestion(MixLevel, division, array, ArrayLength);
        }
        else {
            PrintQuestion(MixLevel, MixType, array, ArrayLength);
        }
    }
}
bool Judge(int win, int loose) {
    if (win > loose) {
        return true;
    }
    else {
        return false;
    }
}
int  WinCounter(int Array[10], int ArrayLength){
    int win = 0;
    for (int i = 0; i < ArrayLength; i++) {
        if (Array[i] == 1) {
            win++;
        }
    }
    return win;
}
int  LooseCounter(int Array[10], int ArrayLength) {
    int loose = 0;
    for (int i = 0; i < ArrayLength; i++) {
        if (Array[i] == 0) {
            loose++;
        }
    }
    return loose;
}
bool CheckWinner(int Array[10], int ArrayLength) {
    int win = 0;
    int loose = 0;
    for (int i = 0; i < ArrayLength; i++) {
        if (Array[i] == 1) {
            win++;
        }
        else if (Array[i] == 0) {
            loose++;
        }
    }
    return Judge(win, loose);
 }
void PrintQuestionType(int QuestionType) {
    if (QuestionType == 1) {
        cout << "Addition" << endl;
    }
    else if (QuestionType == 2) {
        cout << "Subtraction" << endl;
    }
    else if (QuestionType == 3) {
        cout << "Multiplication" << endl;
    }
    else if (QuestionType == 4) {
        cout << "Division" << endl;
    }
    else if (QuestionType == 5) {
        cout << "Mix" << endl;
    }
}
void PrintExamLevel(int ExamLevel) {
    if (ExamLevel == 1) {
        cout << "Easy" << endl;
    }
    else if (ExamLevel == 2) {
        cout << "Medium" << endl;
    }
    else if (ExamLevel == 3) {
        cout << "Hard" << endl;
    }
    else if (ExamLevel == 4) {
        cout << "Mix" << endl;
    }
    
}
void FinalResaults(bool win,int WinCount,int LooseCount,int QuestionType,int NumberOfQuestions,int ExamLevel,int Array[10],int ArrayLength) {
    cout << "-----------------------------------------\n";
    string status;
    if (win) {
        status = "PASSED";
    }
    else {
        status = "FAILED";
    }
    cout << "Exam Resault : "<<status<<endl;
    cout << endl;
    cout << "-----------------------------------------\n";
    cout << "Number of questions : " << NumberOfQuestions << endl;
    cout << "Questions level : ";
    PrintExamLevel(ExamLevel);
    cout << "Question type : ";
    PrintQuestionType(QuestionType);
    cout << "Number of right questions " << WinCounter(Array, ArrayLength)<<endl;
    cout << "Number of wrong questions " << LooseCounter(Array, ArrayLength) << endl;
    cout << endl;
    cout << "-----------------------------------------\n";
}
void ClearSystem() {
    //clears the system
    system("color 00");
    system("cls");
}
void StartExam() {
    //exam execuation
    //should have used a structure for the following variables
    int NumberOfQuestions=0;
    int UserLevel=0;
    int QuestionType = 0;
    int Array[10];
    int ArrayLength = 0;
    char Choice;//play again or no
    cout << "Welcome to the Math Exam: \n";
    cout << "How many questions do you want to answer (1/10) : \n";
    NumberOfQuestions = ValidatePostiveNumberBetweenTwoNumbers(1,10);
    cout << "-----------------------------------------\n";
    cout << "Please enter your level:\n1-Easy 2-Medium 3-Hard 4-Mix\n";
   UserLevel= ValidatePostiveNumberBetweenTwoNumbers(1, 4);
   cout << "Please enter question type:\n1-Addtion 2-Subtraction 3-Multiplication 4-Division 5-Mix\n";
   QuestionType = ValidatePostiveNumberBetweenTwoNumbers(1, 5);
   for (int i = 1; i <= NumberOfQuestions; i++) {
       cout << "Question number : " << i<<endl;
       ExamQuestion(QuestionType, UserLevel,Array,ArrayLength);
       system("color 00");
   }
   FinalResaults(CheckWinner(Array,ArrayLength), WinCounter( Array,  ArrayLength), LooseCounter(Array, ArrayLength), QuestionType, NumberOfQuestions,UserLevel,Array,ArrayLength);
   cout << "Do you want to try again ? (Y/N)" << endl;
   cin >> Choice;
   if (Choice == 'Y' || Choice == 'y') {
       ClearSystem();
       StartExam();
   }
   }
int main()
{
    srand((unsigned)time(NULL));
    StartExam();
    return 0;
}

