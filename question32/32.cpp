class Solution {
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // Step 1: Sort the stalls
        sort(stalls.begin(), stalls.end());
        
        // Step 2: Define the search range
        int low = 1; // Minimum possible distance
        int high = stalls.back() - stalls.front(); // Maximum possible distance
        int result = 0;
        
        // Step 3: Binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if placing cows with at least 'mid' distance is possible
            if (isPossible(stalls, k, mid)) {
                result = mid; // Update result
                low = mid + 1; // Try for a larger minimum distance
            } else {
                high = mid - 1; // Try for a smaller minimum distance
            }
        }
        
        return result;
    }
    
private:
    bool isPossible(const vector<int> &stalls, int k, int dist) {
        int count = 1; // Place the first cow in the first stall
        int lastPosition = stalls[0];
        
        // Place the remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= dist) {
                count++;
                lastPosition = stalls[i];
                if (count == k) {
                    return true;
                }
            }
        }
        
        return false;
    }
};