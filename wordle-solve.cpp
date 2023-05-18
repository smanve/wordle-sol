// Need to make a C++ Wordle Solver

#Include<iostream.h>
#Include<string.h>
#Include<vector>
#Include<fstream>

using namespace std;

int main(){
ifstream inFile;   
inFile.open("words.txt");

if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
}

}