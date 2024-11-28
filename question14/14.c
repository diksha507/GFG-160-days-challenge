class Solution {
  public:
    int myAtoi(char *s) {
        int i = 0, sign = 1;
        long result = 0;

        // Step 1: Skip leading whitespaces
        while (s[i] == ' ') i++;

        // Step 2: Check for a sign
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read digits and construct the integer
        while (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');

            // Step 4: Check for overflow/underflow
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;

            i++;
        }

        // Step 5: Return the final result with the appropriate sign
        return (int)(result * sign);
    }
};