#include "genlib.h"
#include "simpio.h"
#include "strutils.h"
#include "vector.h"




#include <ios>
#include <fstream>
#include <sstream>
#include <iostream>

#define TEST 0
void AssignmentOne_ProblemOne();
void AssignmentOne_ProblemTwo();
void AssignmentOne_ProblemThree();
void AssignmentOne_ProblemFour();
void AssignmentOne_ProblemFive();


int Main(){
    int i;
    
    cout << "Please choose the Assignment Problem from below:"<<endl;
    cout<<"1. Remove all occurences of the character."<<endl;
    cout<<"2. Student Statstics from the file -Min, Max and Average Marks"<<endl;
    cout<<"3. Count the letters Problem"<<endl;
    cout<<"4. Memory Diagram Problem"<<endl;
    cout<<"Enter Assignment problem number:";
    i = GetInteger();
    
    switch(i){
        case 1:
            cout<<"Assignment One:"<<endl;
            AssignmentOne_ProblemOne();
            break;
        case 2:
            cout<<"Assignment Two:"<<endl;
            AssignmentOne_ProblemTwo();
            break;
        case 3:
            cout<<"Assignment Three"<<endl;
            AssignmentOne_ProblemThree();
            break;
        case 4:
            cout<<"Assignment Four"<<endl;
            AssignmentOne_ProblemFour();
            break;
        case 5:
            cout<<"Assignment Five"<<endl;
            AssignmentOne_ProblemFive();
            break;
            
    }
    return 0;
}

/********************************** Problem One***************************************/

string CensorString1 (string text, string remove);
void CensorString2(string & text, string remove);


void AssignmentOne_ProblemOne(){
    string original, remove, result;
    
    cout<<"Please enter the Original Text: ";
    original = GetLine();
    cout<<"Please enter the chatacters to be removed: ";
    remove = GetLine();
    
    result = CensorString1(original, remove);
    cout<<"Original String: "<<original<<" and after CensorString1(string text, string remove) function transformation, the new string is "<<result<<endl;
    
    CensorString2(original, remove);
    cout<<"Original String after CensorString2(string & text, string remove) transformation is "<<original<<endl;
}

string CensorString1 (string text, string remove){
    string result;
    for(int i = 0; i < text.length(); i++){
        if(remove.find(text[i]) == string::npos){
            result += text[i];
        }
    }
    return result;
}

void CensorString2(string & text, string remove){
    for(int i = 0; i < text.length(); i++){
        if(remove.find(text[i]) != string::npos){
            text = text.erase(i, 1);
        }
    }
}

/******************************** Problem Two***********************************************/
#define MAX_STUDENT 1000

struct studentT{
    string name;
    double minNumber, average, maxNumber;
};
struct studentRecord{
    studentT listOfStudents[MAX_STUDENT];
    int numberOfStudents;
};

void AskUserForInputFile(string prompt, ifstream & infile);
void ReadStudentRecords(ifstream & infile, studentRecord & classRecord);
void DisplayStudentRecords(studentRecord classRecord);
void fitInTheStructure(studentRecord & classRecord, string line, int count);


void AssignmentOne_ProblemTwo(){
    ifstream infile;
    AskUserForInputFile("Input file name :", infile);
    studentRecord classRecord;
    ReadStudentRecords(infile, classRecord);
    infile.close();
    DisplayStudentRecords(classRecord);
}

void AskUserForInputFile(string prompt, ifstream & infile){
    while(true){
        cout<<prompt;
        string filename = GetLine();
        filename = "/Users/rahulsachdeva/Documents/My Folder/Learn/Technical/Computer Science/Dev/Programming Abstraction/Assignment One/Assignment1/Assignment1/" + filename;
        infile.open(filename.c_str());
        if(!infile.fail()) break;
        cout<<"Unable to open "<<filename<<endl;
        infile.clear();
    }
}

void ReadStudentRecords(ifstream & infile, studentRecord & classRecord){
    int count = 0;
    while(true && count < MAX_STUDENT){
        string line;
        getline(infile, line);
        if(infile.fail())break;
        fitInTheStructure(classRecord, line, count);
        count++;
    }
    classRecord.numberOfStudents = count;
}

/* Assumes that entry in student records file is in the following format
 *   format:       name max average min
 */
void fitInTheStructure(studentRecord & classRecord, string line, int count){
    
    studentT & currentStudent = classRecord.listOfStudents[count];
    
    classRecord.listOfStudents[count].name = line.substr(0, line.find(' '));
    
    line = line.substr(line.find(' ') + 1);
    currentStudent.minNumber = StringToReal(line.substr(0, line.find(' ')));
    
    line = line.substr(line.find(' ') + 1);
    classRecord.listOfStudents[count].average = StringToReal(line.substr(0, line.find(' ')));
    
    line = line.substr(line.find(' ') + 1);
    classRecord.listOfStudents[count].maxNumber = StringToReal(line);
}

void DisplayStudentRecords(studentRecord classRecord){
    for(int i = 0; i < classRecord.numberOfStudents; i++){
        studentT currentStudent = classRecord.listOfStudents[i];
        cout<<currentStudent.name<<" "<<currentStudent.minNumber<<" "<<currentStudent.average<<" "<<currentStudent.maxNumber<<endl;
    }
}

/***************************************Problem Three*****************************************************/
#define NUMBER_OF_CHARACTERS 26

void CountCharacters(ifstream & infile, Vector<int> & characterCount);
void printCharacterCount(Vector<int> characterCount);

void AssignmentOne_ProblemThree(){
    ifstream infile;
    AskUserForInputFile("Please input the file name: ", infile);
    
    Vector<int> characterCount;
    for(int i = 0; i < NUMBER_OF_CHARACTERS; i++){
        characterCount.add(0);
    }
    
    CountCharacters(infile, characterCount);
    infile.close();
    printCharacterCount(characterCount);
}

void CountCharacters(ifstream & infile, Vector<int> & characterCount){
    while(true){
        int ch = infile.get();
        if(infile.fail() || ch == EOF)break;
        if(isalpha(ch)){
            int pos = tolower(ch) - (int)'a';
            characterCount[pos] += 1;
        }
    }
}

void printCharacterCount(Vector<int> characterCount){
    for(int i = 0; i < NUMBER_OF_CHARACTERS; i++){
        cout<<left<<setw(5)<<char(i + (int)'a')<<right<<setw(5)<<characterCount[i]<<endl;
    }
}

/*******************************Problem Four************************************************/

struct heroT {
  string name;
  string weakness;
  int powerLevel;
};
struct villianT {
  string name;
  string evilPlan;
  int attackLevel;
};
void Battle(heroT aang, villianT & zuko)
{
  int pos = 1;
  int level = aang.powerLevel;
  string name = zuko.name;
while(level > 20)
  {
    zuko.evilPlan[pos--] -= (level / 10);
level /= 2; }
  zuko.attackLevel -= level;
  pos = name.find(aang.weakness);
  while(pos != string::npos)
  {
     aang.powerLevel /= 2;
     name.replace(pos, 2, "");
     pos = name.find(aang.weakness, pos);
}
  if(aang.powerLevel > zuko.attackLevel)
  {
    zuko.name = "Loser";
  }
else {
    aang.name = "Big Baby";
  }
  /* DRAW THE STATE OF MEMORY HERE */
    
return; }

void AssignmentOne_ProblemFour(){
  heroT julie;
  villianT tom;
  julie.name = "Super Lecturer";
  julie.weakness = "Gr";
  julie.powerLevel = 60;
  tom.name = "Grumpy Grad Student";
  tom.evilPlan = "Frowning";
  tom.attackLevel = 30;
  Battle(julie, tom);
}
/****************************Probelm Five*****************/
void PrimeUserFIle(ifstream & infile);
void ExtractPrintIncludeStatements(ifstream & infile);

void AssignmentOne_ProblemFive(){
    ifstream infile;
    PrimeUserFIle(infile);
    ExtractPrintIncludeStatements(infile);
}

void PrimeUserFIle(ifstream & infile){
    string filename = "/Users/rahulsachdeva/cs106/Extractor.txt";
    infile.open(filename.c_str());
    if(infile.fail()) cout<<"Unable to open the file"<<endl;
}

void ExtractPrintIncludeStatements(ifstream & infile){
    string line;
    while(true){
        getline(infile, line);
        if(infile.fail())break;
        if(line.find("#include") != string::npos){
            cout<<line<<endl;
        }
    }
}
