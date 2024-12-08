#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Sort intervals based on the start time
        sort(arr.begin(), arr.end());

        vector<vector<int>> merged;
        
        for (const auto& interval : arr) {
            // If merged is empty or current interval does not overlap with the last merged interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlapping intervals, merge by updating the end time
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};