/*****************************************Problem Four*******************************************/
char MostFrequentCharacter(ifstream & inputStream, int & numOccurrences);
void AskUserForInputFile(string prompt, ifstream & infile);
void MapTheCharacters(ifstream & inputStream, Map<int> & characterFrequency);
char FindTheMostFrequentCharacter(Map<int> characterFrequency, int & numOccurences);

void AssignmentTwo_ProblemFour(){
    ifstream inputStream;
    AskUserForInputFile("Please input the file name: ", inputStream);
    int numOccurences;
    cout<<"Most occurend character in the given file is "<<MostFrequentCharacter(inputStream, numOccurences)<<" and it occured "<<numOccurences<<" times."<<endl;
}

char MostFrequentCharacter(ifstream & inputStream, int & numOccurrences){
    Map<int> characterFrequency;
    MapTheCharacters(inputStream, characterFrequency);
    return FindTheMostFrequentCharacter(characterFrequency, numOccurrences);
}

void MapTheCharacters(ifstream & inputStream, Map<int> & characterFrequency){
    char ch;
    string charInString;
    while(true){
        ch = inputStream.get();
        if(inputStream.fail())break;
        if(isalpha(ch)){
            charInString = ch;
            charInString = ConvertToLowerCase(charInString);
            if(characterFrequency.containsKey(charInString)){
                characterFrequency[charInString] ++ ;
            }else{
                characterFrequency.add(charInString, 1);
            }
        }
    }
}

char FindTheMostFrequentCharacter(Map<int> characterFrequency, int & numOcurences){
    Map<int>::Iterator iter = characterFrequency.iterator();
    string temp, mostFrequent;
    for(int i = 0; iter.hasNext(); i++){
        temp = iter.next();
        if(i == 0) mostFrequent = temp;
        if(characterFrequency.getValue(temp) > characterFrequency.getValue(mostFrequent)){
            mostFrequent = temp;
        }
    }
    numOcurences = characterFrequency.getValue(mostFrequent);
    return mostFrequent[0];
}

/************************************Problem  Five******************************************/
void MakeGridOfCounts(Grid<bool> & bombLocations);
int boolToInt(bool input);
bool isSpaceOnLeft(Grid<int> grid,int row, int col);
bool isSpaceOnRight(Grid<int> grid,int row, int col);
bool isSpaceOnTop(Grid<int> grid,int row, int col);
bool isSpaceOnBottom(Grid<int> grid,int row, int col);

void AssignmentTwo_ProblemFive(){
    Grid<bool> bombLocations(6,6);
    for(int i = 0; i < bombLocations.numRows(); i++){
        for(int j = 0; j< bombLocations.numCols(); j++){
            bombLocations(i,j) = RandomChance(.5);
        }
    }
    
    cout<<"Printing the bombLocations Matrix"<<endl;
    for(int i = 0; i < bombLocations.numRows(); i++){
        for(int j = 0; j < bombLocations.numCols(); j++){
            cout<<bombLocations(i,j)<<" ";
        }
        cout<<endl;
    }
    MakeGridOfCounts(bombLocations);
}

void MakeGridOfCounts(Grid<bool> & bombLocations){
    Randomize();
    Grid<int> gridOfCount(bombLocations.numRows(), bombLocations.numCols());
    for(int i = 0; i < gridOfCount.numRows(); i++){
        for(int j = 0; j < gridOfCount.numCols(); j++){
            gridOfCount(i, j) = 0;
            if(isSpaceOnLeft(gridOfCount, i, j)){
                gridOfCount(i,j) += boolToInt(bombLocations(i - 1, j));
                if(isSpaceOnTop(gridOfCount, i, j)){
                    gridOfCount(i,j) += boolToInt(bombLocations(i - 1, j - 1));
                }
                if(isSpaceOnBottom(gridOfCount, i, j)){
                    gridOfCount(i,j) += boolToInt(bombLocations(i - 1, j + 1));
                }
            }
            if(isSpaceOnRight(gridOfCount, i, j)){
                gridOfCount(i,j) += boolToInt(bombLocations(i + 1, j));
                if(isSpaceOnTop(gridOfCount, i, j)){
                    gridOfCount(i,j) += boolToInt(bombLocations(i + 1, j - 1));
                }
                if(isSpaceOnBottom(gridOfCount, i, j)){
                    gridOfCount(i,j) += boolToInt(bombLocations(i + 1, j + 1));
                }
            }
            if(isSpaceOnTop(gridOfCount, i, j)){
                gridOfCount(i,j) += boolToInt(bombLocations(i, j - 1));
            }
            if(isSpaceOnBottom(gridOfCount, i, j)){
                gridOfCount(i,j) += boolToInt(bombLocations(i, j + 1));
            }
        }
    }
    
    cout<<"Printing the GridOfCount Matrix"<<endl;
    for(int i = 0; i < gridOfCount.numRows(); i++){
        for(int j = 0; j < gridOfCount.numCols(); j++){
            cout<<gridOfCount(i,j)<<" ";
        }
        cout<<endl;
    }
}

int boolToInt(bool input){
    return input? 1: 0;
}

bool isSpaceOnLeft(Grid<int> grid,int row, int col){
    return row > 0;
}

bool isSpaceOnRight(Grid<int> grid,int row, int col){
    return row < grid.numRows() - 1;
}

bool isSpaceOnTop(Grid<int> grid,int row, int col){
    return col > 0;
}

bool isSpaceOnBottom(Grid<int> grid,int row, int col){
    return col < grid.numCols() - 1;
}

/*************************PROGRAMMING ASSIGNMENT  2***************************/

void ProgrammingAssignmentTwo_ProblemOne();
void ProgrammingAssignmentTwo_ProblemTwo();

int Main(){
    
    int i;
    
    cout<<"Please choose the Programming Assignment Problem from below:"<<endl;
    cout<<"1. Random Writing."<<endl;
    cout<<"2. Reverse Queue"<<endl;
    cout<<"3. HTML Tags Checker"<<endl;
    cout<<"4. Character with highest frequency finder"<<endl;
    cout<<"5. Making Grid of counts"<<endl;
    cout<<"Choose the second Assignment problem number: ";
    
    i = GetInteger();
    
    switch(i){
        case 1:
            cout<<"Problem One:"<<endl;
            ProgrammingAssignmentTwo_ProblemOne();
            break;
        case 2:
            cout<<"Problem Two:"<<endl;
            ProgrammingAssignmentTwo_ProblemTwo();
            break;
        case 3:
            cout<<"Problem Three"<<endl;
            //AssignmentTwo_ProblemThree();
            break;
        case 4:
            cout<<"Problem Four"<<endl;
            AssignmentTwo_ProblemFour();
            break;
        case 5:
            cout<<"Problem Five"<<endl;
            AssignmentTwo_ProblemFive();
    }
    return 0;
}

/*****************Programming Assignment TWO Problem ONE********************/
void AskUserForInputFile(string prompt, ifstream & infile);
void SourceTextAnalysis(ifstream & infile, Map<Vector<int> > & sourceTextRecord, int  markovOrder);
void GenerateRandomText(Map<Vector<int> > & sourceTextRecord, int  markovOrder, int numberOfCharacters, string seed);
string PrintTheMap(Map<Vector<int> > & sourceTextRecord);

void ProgrammingAssignmentTwo_ProblemOne(){
    ifstream infile;
    AskUserForInputFile("Please input the file name to be read: ", infile);
    cout<<"Please input the Markov Order: ";
    int markovOrder = GetInteger();
    Map<Vector<int> > sourceTextRecord;
    SourceTextAnalysis(infile, sourceTextRecord, markovOrder);
    string seedMaxFrequency = PrintTheMap(sourceTextRecord);
    cout<<"Please entrer the number of charaters you want to generate: ";
    int numberOfCharacters = GetInteger();
    GenerateRandomText(sourceTextRecord, markovOrder, numberOfCharacters, seedMaxFrequency);
    
}

void AskUserForInputFile(string prompt, ifstream & infile){
    while(true){
        cout<<prompt;
        string filename = GetLine();
        filename = "/Users/rahulsachdeva/Documents/My Folder/Learn/Technical/Computer Science/Dev/Programming Abstraction/Programming Assignment Two/ProgAbstraction_ProgAssignTwo/ProgAbstraction_ProgAssignTwo/" + filename;
        infile.open(filename.c_str());
        if(!infile.fail()) break;
        cout<<"Unable to open "<<filename<<endl;
        infile.clear();
    }
}

void SourceTextAnalysis(ifstream & infile, Map<Vector<int> > & sourceTextRecord, int  markovOrder){
    
    string tempString;
    int temp;
    Vector<int> tempVector;
    while(true){
        temp = infile.get();
        tempString += temp;
        if(tempString.length() > markovOrder){
            if(sourceTextRecord.containsKey(tempString.substr(0, tempString.length() - 1))){
                tempVector = sourceTextRecord.getValue(tempString.substr(0, tempString.length() - 1));
                tempVector.add(temp);
                sourceTextRecord.add(tempString.substr(0, tempString.length() -1), tempVector);
                cout<<"Found One "<<tempString.substr(0, tempString.length() - 1)<<" "<<sourceTextRecord.get(tempString.substr(0, tempString.length() - 1)).size()<<endl;
                tempVector.clear();
            }else{
                tempVector.add(temp);
                sourceTextRecord.add(tempString.substr(0, tempString.length() -1), tempVector);
                tempVector.clear();
            }
            cout<<tempString.substr(0, tempString.length() - 1)<<" "<<(char)temp<<endl;
            tempString = tempString.substr(1);
        }
        if(temp == EOF) break;
    }
    if(tempString.length() < markovOrder)
        cout<<"Input text is not sufficient for "<< markovOrder<< "th markov order system."<<endl;
}

string PrintTheMap(Map<Vector<int> > & sourceTextRecord){
    cout<<endl<<endl;
    string temp, maxFrequency;
    Map<Vector<int> >::Iterator mapIter = sourceTextRecord.iterator();
    for(int i = 0; mapIter.hasNext(); i++){
        temp = mapIter.next();
        if(i == 0)maxFrequency = temp;
        if(sourceTextRecord.getValue(temp).size() > sourceTextRecord.get(maxFrequency).size()){
            maxFrequency = temp;
        }
        cout<<temp<<" ";
        Vector<int>::Iterator iter = sourceTextRecord.getValue(temp).iterator();
        while(iter.hasNext()){
            cout<<(char)iter.next()<<" ";
        }
        cout<<endl;
    }
    cout<<"maxFrequency "<<maxFrequency<<" "<<sourceTextRecord.get(maxFrequency).size()<<endl;
    return maxFrequency;
}

void GenerateRandomText(Map<Vector<int> > & sourceTextRecord, int  markovOrder, int numberOfCharacters, string seed){
    string currentSeed = seed, outputText = seed;
    char nextCharacter;
    for(int i = 0; i < numberOfCharacters; i++){
        nextCharacter  = (char)sourceTextRecord.get(currentSeed).getAt(RandomInteger(0, sourceTextRecord.get(currentSeed).size() - 1));
        outputText += nextCharacter;
        currentSeed = currentSeed.substr(1) + nextCharacter;
        if(nextCharacter == EOF) break;
    }
    cout<<outputText;
}
/**********************Programming Assignment TWO Problem TWO**************/

void GenerateThePerfectMaze(Maze & inputMaze);
pointT FindNeighbour(Maze & inputMaze, Set<pointT> & incPoints, pointT & currentPoint);
void GenerateStartAndEndPoints(Maze & inputMaze, pointT & startP, pointT & endP);
void FindPathStartToEnd(Maze & inputMaze, pointT & startP, pointT & endP);

void ProgrammingAssignmentTwo_ProblemTwo(){
    Maze inputMaze = Maze(10, 20, true);
    inputMaze.draw();
    GenerateThePerfectMaze(inputMaze);
    cout<<"Done"<<endl;
    pointT startP, endP;
    GenerateStartAndEndPoints(inputMaze, startP, endP);
    FindPathStartToEnd(inputMaze, startP, endP);
}

int comparePointT(pointT pointOne, pointT pointTwo){
    if(pointOne.row > pointTwo.row){
        return 1;
    }else if(pointOne.row == pointTwo.row && pointOne.col == pointTwo.col){
        return 0;
    }else return -1;
}

void GenerateThePerfectMaze(Maze & inputMaze){
    Set<pointT> incPoints(comparePointT);
    pointT currentPoint, neighbourPoint;
    currentPoint.row = RandomInteger(0, inputMaze.numRows());
    currentPoint.col = RandomInteger(0, inputMaze.numCols());
    while(incPoints.size() < inputMaze.numCols()*inputMaze.numRows()){
        neighbourPoint = FindNeighbour(inputMaze, incPoints, currentPoint);
        if(inputMaze.isWall(currentPoint, neighbourPoint)){
            inputMaze.setWall(currentPoint, neighbourPoint, false);
            cout<<"Done with setWall module"<<endl;
        }
        incPoints.add(neighbourPoint);
        currentPoint = neighbourPoint;
    }
}

pointT FindNeighbour(Maze & inputMaze, Set<pointT> & incPoints, pointT & currentPoint){
    pointT neighbourPoint;
    Vector<pointT> vectorOfNeighbours, vectorOfNonIncPoints;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(i + j != 0 && i != j){
                cout<<"FindNeighbour"<<endl;
                neighbourPoint.row = currentPoint.row + i;
                neighbourPoint.col = currentPoint.col + j;
                if(inputMaze.pointInBounds(neighbourPoint)){
                    vectorOfNeighbours.add(neighbourPoint);
                    if(! incPoints.contains(neighbourPoint)){
                        vectorOfNonIncPoints.add(neighbourPoint);
                    }
                }
            }
        }
    }
    if(vectorOfNonIncPoints.size() != 0)
        return vectorOfNonIncPoints[RandomInteger(0, vectorOfNonIncPoints.size() - 1)];
    else return vectorOfNeighbours[RandomInteger(0, vectorOfNeighbours.size() - 1)];
}

void GenerateStartAndEndPoints(Maze & inputMaze, pointT & startP, pointT & endP){
    startP.row = RandomInteger(0, inputMaze.numRows());
    startP.col = RandomInteger(0, inputMaze.numCols());
    while(true){
        endP.row = RandomInteger(0, inputMaze.numRows());
        endP.col = RandomInteger(0, inputMaze.numCols());
        if(comparePointT(startP, endP))break;
    }
}

Vector<pointT> FindNextPossiblePoints(pointT currentPoint, Maze & inputMaze);
Stack<pointT> FindSmallestPath(Vector<Stack<pointT> > & possiblePaths);

void FindPathStartToEnd(Maze & inputMaze, pointT & startP, pointT & endP){
    Vector<Stack<pointT> > possiblePaths;
    Stack<pointT> currentPath, newPath;
    Vector<pointT> possibleNextPoints;
    currentPath.push(startP);
    possiblePaths.add(currentPath);
    while(true){
        currentPath = FindSmallestPath(possiblePaths);
        possibleNextPoints = FindNextPossiblePoints(currentPath.peek(), inputMaze);
        for(int i = 0; i < possibleNextPoints.size(); i++){
            newPath = currentPath;
            newPath.push(possibleNextPoints[i]);
            possiblePaths.add(newPath);
            if(!(comparePointT(possibleNextPoints[i], endP))) break;
        }
        if(!(comparePointT(endP, possiblePaths[possiblePaths.size() - 1].peek())))break;
    }
    currentPath = possiblePaths[possiblePaths.size() - 1];
    while(currentPath.isEmpty()){
        inputMaze.drawMark(currentPath.pop(), "Black");
    }
}

Vector<pointT> FindNextPossiblePoints(pointT currentPoint, Maze & inputMaze){
    Vector<pointT> output;
    pointT neighbourPoint;
    for(int i = - 1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(i != j && i + j != 0){
                neighbourPoint.row = currentPoint.row + i;
                neighbourPoint.col = currentPoint.col + j;
                if(!inputMaze.isWall(currentPoint, neighbourPoint)){
                    output.add(neighbourPoint);
                }
            }
        }
    }
    return output;
}

Stack<pointT> FindSmallestPath(Vector<Stack<pointT> > & possiblePaths){
    int smallest = 0;
    Stack<pointT> output;
    for(int i = 0; i < possiblePaths.size(); i++){
        if(possiblePaths[i].size() < possiblePaths[smallest].size())
            smallest = i;
    }
    output = possiblePaths[smallest];
    possiblePaths.removeAt(smallest);
    return output;
}
