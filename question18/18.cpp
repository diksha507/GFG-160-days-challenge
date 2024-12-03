class Solution {
public:
    int minChar(string& s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string concat = s + "#" + rev;

        // Compute LPS array
        int m = concat.size();
        vector<int> lps(m, 0);
        for (int i = 1; i < m; i++) {
            int len = lps[i - 1];
            while (len > 0 && concat[i] != concat[len]) {
                len = lps[len - 1];
            }
            if (concat[i] == concat[len]) {
                len++;
            }
            lps[i] = len;
        }

        // Minimum characters to add = n - length of longest palindromic suffix
        return n - lps[m - 1];
    }
};