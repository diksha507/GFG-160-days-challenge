#include <vector>
using namespace std;

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the key
            if (arr[mid] == key) {
                return mid;
            }

            // Determine which part is sorted
            if (arr[low] <= arr[mid]) { // Left part is sorted
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1; // Search in the left sorted part
                } else {
                    low = mid + 1; // Search in the right unsorted part
                }
            } else { // Right part is sorted
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1; // Search in the right sorted part
                } else {
                    high = mid - 1; // Search in the left unsorted part
                }
            }
        }

        // If the key is not found
        return -1;
    }
};