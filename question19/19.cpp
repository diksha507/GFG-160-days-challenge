class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Check if the lengths are different.
        if (s1.length() != s2.length()) {
            return false;
        }
        // Concatenate s1 with itself.
        string s1s1 = s1 + s1;
        // Check if s2 is a substring of s1s1.
        return (s1s1.find(s2) != string::npos);
    }
};