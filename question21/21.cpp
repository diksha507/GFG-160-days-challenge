#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Sort citations in descending order
        sort(citations.rbegin(), citations.rend());
        
        int h = 0; // Initialize H-index to 0
        
        // Iterate over the sorted array
        for (int i = 0; i < citations.size(); ++i) {
            // Check if the number of papers is <= the citations for that paper
            if (i + 1 <= citations[i]) {
                h = i + 1; // Update H-index
            } else {
                break;
            }
        }
        return h;
    }
};