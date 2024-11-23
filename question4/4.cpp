

class Solution {
  public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size(); // Size of the array
        d = d % n;          // Handle cases where d >= n
        
        // Step 1: Reverse the first d elements
        reverse(arr.begin(), arr.begin() + d);
        
        // Step 2: Reverse the remaining elements
        reverse(arr.begin() + d, arr.end());
        
        // Step 3: Reverse the entire array
        reverse(arr.begin(), arr.end());
    }
};
   
   
   
   
