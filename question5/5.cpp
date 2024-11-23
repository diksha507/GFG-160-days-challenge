// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the end
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        if (i >= 0) { // If a valid i is found
            // Step 2: Find the smallest element greater than arr[i] from the end
            int j = n - 1;
            while (j > i && arr[j] <= arr[i]) {
                j--;
            }
            // Step 3: Swap arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }

        // Step 4: Reverse the subarray from i + 1 to the end
        reverse(arr.begin() + i + 1, arr.end());
    }
};
