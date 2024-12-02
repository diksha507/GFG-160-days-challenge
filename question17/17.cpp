class Solution {
public:
    // Function to create the LPS array
    void computeLPSArray(string& pat, vector<int>& lps) {
        int len = 0; // Length of the previous longest prefix suffix
        lps[0] = 0; // lps[0] is always 0
        int i = 1;

        while (i < pat.size()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Function to search pattern in the text
    vector<int> search(string& pat, string& txt) {
        int M = pat.size();
        int N = txt.size();

        vector<int> lps(M);
        computeLPSArray(pat, lps);

        vector<int> result;
        int i = 0; // index for txt
        int j = 0; // index for pat

        while (i < N) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == M) {
                // Pattern found at index i-j
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};