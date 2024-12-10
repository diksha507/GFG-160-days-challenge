#include <vector>
#include <algorithm>

class Solution {
public:
    int minRemoval(std::vector<std::vector<int>> &intervals) {
        // Sort intervals by their ending times
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int prevEnd = intervals[0][1];
        int removals = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prevEnd) {
                // Overlapping interval, increment removal count
                ++removals;
            } else {
                // Update the end time of the last non-overlapping interval
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
};