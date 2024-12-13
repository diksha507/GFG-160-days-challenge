#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is less than the high element, move left
            if (arr[mid] < arr[high]) {
                high = mid;
            } 
            // If mid element is greater than the high element, move right
            else if (arr[mid] > arr[high]) {
                low = mid + 1;
            } 
            // If duplicates, shrink search space
            else {
                high--;
            }
        }
        return arr[low];
    }
};