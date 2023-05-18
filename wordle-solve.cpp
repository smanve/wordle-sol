// Need to make a C++ Wordle Solver

#include<iostream.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int main(){
ifstream inFile;   
string guess;
string feedback;
inFile.open("words.txt");

if (inFile.is_open()) {
        string word;
        while (getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cout << "Failed to open the file: " << filename << std::endl;
    }
std::cout << "Welcome to Wordle Solver!\n";
std::cout << "Enter your guess: ";
std::cin >> guess;

std::cout << "Enter the feedback: ";
std::cin >> feedback;

transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
transform(feedback.begin(), feedback.end(), feedback.begin(), ::tolower);
}