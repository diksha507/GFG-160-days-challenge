class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1;  // Pointer for s1
        int j = s2.size() - 1;  // Pointer for s2
        int carry = 0;          // Carry for binary addition
        string result = "";     // Resultant binary string

        // Process both strings from the end
        while (i >= 0 || j >= 0 || carry) {
            int bit1 = (i >= 0) ? s1[i] - '0' : 0;  // Get bit from s1 or 0
            int bit2 = (j >= 0) ? s2[j] - '0' : 0;  // Get bit from s2 or 0

            int sum = bit1 + bit2 + carry;          // Sum of bits and carry
            result = char((sum % 2) + '0') + result;  // Add current bit to result
            carry = sum / 2;                        // Update carry

            i--;  // Move pointer for s1
            j--;  // Move pointer for s2
        }

        // Remove leading zeros from the result
        int pos = 0;
        while (pos < result.size() - 1 && result[pos] == '0') {
            pos++;
        }

        return result.substr(pos);
    }
};