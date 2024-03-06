#include<iostream>
#include<vector>

using namespace std;

// check if a string is a palindrome or not:

// "arara"
// "radar"
// " "

//complexities:
// O(n) time
// O(1) space

bool isPalindrome(const string& word) {
    int i = 0;  // Start index
    int j = word.size() - 1;  // End index
    while (i < j) {  // While start index is less than end index
        // Skip non-alphanumeric characters from the left
        while (i < j && !isalnum(word[i]))
            i++;
        // Skip non-alphanumeric characters from the right
        while (i < j && !isalnum(word[j]))
            j--;
        // Check if characters are equal ignoring case
        if (tolower(word[i]) != tolower(word[j]))
            return false;  // If not equal, it's not a palindrome
        // Move pointers inward
        i++;
        j--;
    }
    return true;  // If loop completes, it's a palindrome
}
int main() {
    // Test cases
    vector<string> testCases = {"arara", "radar", "", "hello", "level", "noon","A man, a plan, a canal: Panama"};
    
    for (const auto& word : testCases) {
        cout << "Is '" << word << "' a palindrome? " << (isPalindrome(word) ? "Yes" : "No") << endl;
    }

    return 0;
}
