#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to merge two sorted halves and count inversions.
    int mergeAndCount(vector<int> &arr, int left, int mid, int right) {
        int i = left;        // Starting index for the left subarray
        int j = mid + 1;     // Starting index for the right subarray
        int k = 0;           // Index for the temporary array
        int count = 0;       // Count of inversions

        vector<int> temp(right - left + 1); // Temporary array

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // Inversion found: all remaining elements in the left subarray
                // are greater than arr[j].
                temp[k++] = arr[j++];
                count += (mid - i + 1);
            }
        }

        // Copy remaining elements from left subarray
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements from right subarray
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the sorted temporary array back to the original array
        for (int i = left, k = 0; i <= right; i++, k++) {
            arr[i] = temp[k];
        }

        return count;
    }

    // Recursive function to divide the array and count inversions
    int mergeSortAndCount(vector<int> &arr, int left, int right) {
        int count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in the left subarray
            count += mergeSortAndCount(arr, left, mid);

            // Count inversions in the right subarray
            count += mergeSortAndCount(arr, mid + 1, right);

            // Count inversions during the merge step
            count += mergeAndCount(arr, left, mid, right);
        }
        return count;
    }

    // Function to count inversions in the array
    int inversionCount(vector<int> &arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};