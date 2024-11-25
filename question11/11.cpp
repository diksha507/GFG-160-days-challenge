
#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    // Function to find the maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        int maxProduct = arr[0];
        int minProduct = arr[0];
        int result = arr[0];
        
        for (int i = 1; i < n; ++i) {
            if (arr[i] < 0) {
                // Swap maxProduct and minProduct when encountering a negative number
                swap(maxProduct, minProduct);
            }
            
            // Update maxProduct and minProduct
            maxProduct = max(arr[i], maxProduct * arr[i]);
            minProduct = min(arr[i], minProduct * arr[i]);
            
            // Update the global result
            result = max(result, maxProduct);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends