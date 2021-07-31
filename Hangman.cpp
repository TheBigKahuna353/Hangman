#include <iostream>
#include <vector>

using namespace std;

void printWord(string word, vector<int> guessed) {
    for (int i = 0; i < word.length(); i = i+1) {
        if (guessed[i] == 1) {
            cout << word[i] << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

char getGuess() {
    cout << "Guess a letter: ";
    char guess;
    cin >> guess;
    return guess;
}

vector<int> checkGuess(char guess, string word, vector<int> guessed) {
    for (int i = 0; i < word.length(); i = i + 1) {
        if (word[i] == guess) {
            guessed[i] = 1;
        }
    }
    return guessed;
}

bool checkWin(vector<int> guessed) {
    for (int i = 0; i < guessed.size(); i = i + 1) {
        if (guessed[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    string word ("test");
    vector<int> guessed (word.length(), 0);
    while (checkWin(guessed) == false) {
        printWord(word, guessed);
        char guess = getGuess();
        guessed = checkGuess(guess, word, guessed);
    }
    cout << "You correctly guessed the word!!!";
    return 0;
}