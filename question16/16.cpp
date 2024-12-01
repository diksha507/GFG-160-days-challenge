#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> freq; // To store the frequency of characters.
        
        // Step 1: Count the frequency of each character.
        for (char c : s) {
            freq[c]++;
        }
        
        // Step 2: Traverse the string to find the first non-repeating character.
        for (char c : s) {
            if (freq[c] == 1) {
                return c; // Return the first non-repeating character.
            }
        }
        
        return '$'; // Return '$' if no non-repeating character is found.
    }
};