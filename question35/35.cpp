#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> result;
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right; i++) {
                result.push_back(mat[top][i]);
            }
            top++; // Move top boundary downward

            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom; i++) {
                result.push_back(mat[i][right]);
            }
            right--; // Move right boundary leftward

            // Traverse from right to left along the bottom boundary (if applicable)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--; // Move bottom boundary upward
            }

            // Traverse from bottom to top along the left boundary (if applicable)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(mat[i][left]);
                }
                left++; // Move left boundary rightward
            }
        }

        return result;
    }
};