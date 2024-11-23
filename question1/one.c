// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second largest element
    int getSecondLargest(vector<int> &arr) {
        // Check if array has fewer than 2 elements
        if (arr.size() < 2) {
            return -1; // No second largest exists
        }

        int largest = INT_MIN, secondLargest = INT_MIN;

        // Find the largest element
        for (int num : arr) {
            if (num > largest) {
                largest = num;
            }
        }

        // Find the second largest element
        for (int num : arr) {
            if (num > secondLargest && num < largest) {
                secondLargest = num;
            }
        }

        return (secondLargest == INT_MIN) ? -1 : secondLargest; // Return -1 if no second largest exists
    }
};
