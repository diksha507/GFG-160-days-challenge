#include <vector>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;
        
        while (mid <= high) {
            if (arr[mid] == 0) {
                // Swap arr[low] and arr[mid], move low and mid forward
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                // Just move mid forward
                mid++;
            } else { // arr[mid] == 2
                // Swap arr[mid] and arr[high], move high backward
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};