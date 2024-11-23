class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0; // If there's only one tower, difference is 0.

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Initial difference between the tallest and shortest towers
        int diff = arr[n - 1] - arr[0];

        // Step 2: Adjust the boundaries
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++) {
            // Minimum height considering current tower
            int minHeight = min(smallest, arr[i + 1] - k);

            // Maximum height considering current tower
            int maxHeight = max(largest, arr[i] + k);

            // Update the minimum difference
            if (minHeight >= 0) { // Ensure no negative heights
                diff = min(diff, maxHeight - minHeight);
            }
        }

        return diff;
    }
};


