

class Solution {
public:
    int numberOfCombinations(string num) {
        int n = num.size();
        if (num[0] == '0') return 0;

        const int MOD = 1e9 + 7;

        // 1. Precalculate Longest Common Prefix (LCP)
        // lcp[i][j] stores the length of the common prefix between num[i...] and num[j...]
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (num[i] == num[j]) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
            }
        }

        // Helper function to check if num[i..i+len-1] <= num[i+len..i+2*len-1]
        auto isLessOrEqual = [&](int i, int len) {
            int common = lcp[i][i + len];
            if (common >= len) return true; // Substrings are equal
            return num[i + common] < num[i + len + common];
        };

        // dp[i][len] = number of valid partitions of suffix num[i...] 
        // where the first number starts at i and has length 'len'
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // pref[i][len] = sum_{k=len}^{n} dp[i][k]
        vector<vector<int>> pref(n + 1, vector<int>(n + 2, 0));

        // Base case: at the end of the string, any single valid remainder is 1 valid path
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0') continue; // Leading zero is invalid

            for (int len = n - i; len >= 1; --len) {
                if (i + len == n) {
                    dp[i][len] = 1;
                } else {
                    int next_start = i + len;
                    
                    // Case 1: Next number length > len
                    int count = pref[next_start][len + 1];

                    // Case 2: Next number length == len (requires comparison)
                    if (next_start + len <= n && isLessOrEqual(i, len)) {
                        count = (count + dp[next_start][len]) % MOD;
                    }

                    dp[i][len] = count;
                }

                // Maintain suffix sum for current row 'i'
                pref[i][len] = (pref[i][len + 1] + dp[i][len]) % MOD;
            }
        }

        return pref[0][1];
    }
};