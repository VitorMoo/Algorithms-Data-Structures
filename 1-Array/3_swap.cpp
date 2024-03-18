#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to reverse a string
void reverseWord(string &word, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        swap(word[i], word[j]);
    }
}

// Function to reverse words in a sentence
void reverseSentence(string &sentence) {
    int start = 0;

    // Reverse the entire sentence
    reverseWord(sentence, 0, sentence.size() - 1); // Reversing the string using reverseWord function
      
    for (int i = start; i < sentence.size(); i++) { // Start at 0 and go until the end of the sentence
        if (sentence[i] == ' ') { // When it finds a blank space, reverse the word and update the start index
            reverseWord(sentence, start, i - 1); // Reverse the word
            start = i + 1; // Update start index to the beginning of the next word
        }
    }
    reverseWord(sentence, start, sentence.size() - 1); // Reverse the last word 
}
/*

ORIGINAL STRING:
--------------
vitor e alice

ecila e rotiv
^    ^
looks to the start and i-1
reverseWord()
--------------
--------------
alice e rotiv
      ^^  
reverseWord()
-------------
alice e rotiv
        ^   ^

theres no blanck space, so we put a reverseWord at the end to finally reverse the last word.
OUTPUT:
alice e vitor
*/

int main() {
    string word1 = "vitor e alice";
    reverseSentence(word1);
    cout << word1;
    return 0;
}
