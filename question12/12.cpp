class Solution {
  public:
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();

        // Case 1: Maximum subarray sum using Kadane's algorithm
        int max_kadane = kadane(arr);
        
        // Case 2: Maximum circular subarray sum
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
            arr[i] = -arr[i]; // Invert the array to find minimum subarray sum
        }

        int min_kadane = kadane(arr);
        int max_circular = total_sum + min_kadane; // total_sum - (-min_kadane)

        // If all elements are negative, max_circular would be 0. In such cases, return max_kadane.
        if (max_circular == 0) {
            return max_kadane;
        }

        return max(max_kadane, max_circular);
    }

  private:
    int kadane(vector<int> &arr) {
        int max_sum = arr[0], current_sum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            current_sum = max(arr[i], current_sum + arr[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};