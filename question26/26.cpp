#include <vector>
#include <cmath> // For ceil
using namespace std;

class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int gap = ceil((n + m) / 2.0); // Initial gap

        while (gap > 0) {
            int i = 0, j = gap;

            while (j < (n + m)) {
                if (j < n && a[i] > a[j]) {
                    swap(a[i], a[j]); // Swap within array a
                } else if (j >= n && i < n && a[i] > b[j - n]) {
                    swap(a[i], b[j - n]); // Swap between array a and b
                } else if (j >= n && i >= n && b[i - n] > b[j - n]) {
                    swap(b[i - n], b[j - n]); // Swap within array b
                }
                i++;
                j++;
            }

            if (gap == 1) {
                gap = 0; // Break the loop
            } else {
                gap = ceil(gap / 2.0); // Reduce the gap
            }
        }
    }
};