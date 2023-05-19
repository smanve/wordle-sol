#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Function to check if a word matches the hints
bool matchesHints(const std::string& word, const std::string& guess, const std::string& feedback) {
    std::string tempFeedback = feedback;

    // Check for correct letters at correct positions
    for (int i = 0; i < guess.size(); ++i) {
        if (guess[i] == word[i]) {
            tempFeedback[i] = '*';
        }
    }

    // Check for correct letters at incorrect positions
    for (int i = 0; i < guess.size(); ++i) {
        if (tempFeedback[i] != '*' && word[i] != guess[i]) {
            tempFeedback[i] = '#'; // Use '#' to represent incorrect letters
        }
    }

    // Compare the feedback with the given feedback
    return tempFeedback == feedback;
}

int main() {
    std::ifstream file("words.txt");
    std::string guess;
    std::string feedback;
    std::vector<std::string> words;

    if (file.is_open()) {
        std::string word;
        while (std::getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::cout << "Welcome to Wordle Solver! Please enter your first guess, then enter your feedback." << std::endl;
    std::cout << "* (asterisk): This symbol represents a correct letter in the correct position." << std::endl;
    std::cout << "# (hash): This symbol represents an incorrect letter." << std::endl;

    std::cout << "Enter your guess: ";
    std::cin >> guess;

    std::cout << "Enter the feedback: ";
    std::cin >> feedback;

    transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

    // Filter the words based on the hints
    std::vector<std::string> matchingWords;
    for (const std::string& word : words) {
        std::string lowerWord = word;
        transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
        if (matchesHints(lowerWord, guess, feedback)) {
            matchingWords.push_back(word);
        }
    }

    // Print the matching words
    std::cout << "\nMatching words: ";
    if (!matchingWords.empty()) {
        std::copy(matchingWords.begin(), matchingWords.end() - 1, std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << matchingWords.back();
    }
    std::cout << std::endl;

    return 0;
}
