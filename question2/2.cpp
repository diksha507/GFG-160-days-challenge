// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int nonZeroIndex = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                arr[nonZeroIndex] = arr[i];
                nonZeroIndex++;
            }
        }

        // Fill the remaining positions with zeros
        while (nonZeroIndex < arr.size()) {
            arr[nonZeroIndex] = 0;
            nonZeroIndex++;
        }
    }
};
  
  
  
  
