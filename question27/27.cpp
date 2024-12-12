#include <vector>
using namespace std;

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int first = findFirst(arr, target);
        if (first == -1) return 0; // target not found
        int last = findLast(arr, target);
        return last - first + 1;
    }
    
private:
    int findFirst(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                high = mid - 1; // search in the left half
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
    
    int findLast(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                low = mid + 1; // search in the right half
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};