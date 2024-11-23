class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size(); // Get the size of the array
        
        // Reverse the array in place
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }

        
    }
};
  
   
  
