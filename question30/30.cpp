class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if the middle element is a peak
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && 
                (mid == n - 1 || arr[mid] > arr[mid + 1])) {
                return mid;
            }

            // If the left neighbor is greater, move to the left half
            if (mid > 0 && arr[mid - 1] > arr[mid]) {
                high = mid - 1;
            } else { 
                // Otherwise, move to the right half
                low = mid + 1;
            }
        }

        return -1; // Should never reach here
    }
};