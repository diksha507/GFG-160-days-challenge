#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function to check if a given maxPages can be a valid allocation
    bool isValid(vector<int>& arr, int n, int k, int maxPages) {
        int students = 1, currentSum = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxPages) {
                return false; // A single book has more pages than allowed maxPages
            }
            
            if (currentSum + arr[i] > maxPages) {
                // Allocate books to next student
                students++;
                currentSum = arr[i];
                
                if (students > k) {
                    return false; // More students needed than available
                }
            } else {
                currentSum += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // Not enough books for all students
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isValid(arr, n, k, mid)) {
                result = mid; // Update result to the current mid
                high = mid - 1; // Try for a smaller maximum
            } else {
                low = mid + 1; // Increase the allowed maximum
            }
        }
        
        return result;
    }
};