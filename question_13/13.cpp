//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        // Step 1: Move all non-positive numbers and numbers greater than n to ignore them
        for (int i = 0; i < n; i++) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        // Step 2: Find the first missing positive number
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If all numbers from 1 to n are present, return n + 1
        return n + 1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends