

class Solution {
public:
    static const long long LIM = 1000001;

    // Helper to compute multinomial coefficient safely
    long long countWays(const vector<int>& cnt, int total) {
        long long ans = 1;
        int rem = total;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            
            // Compute C(rem, cnt[i]) while preventing overflow
            long long curComb = 1;
            int r = cnt[i];
            int n = rem;
            
            if (r > n - r) r = n - r; // Use symmetry C(n, r) = C(n, n-r)
            
            for (int j = 1; j <= r; ++j) {
                curComb = curComb * (n - j + 1) / j;
                if (curComb > LIM) {
                    curComb = LIM;
                }
            }

            // Multiply with running answer safely
            ans = min(LIM, ans * curComb);
            rem -= cnt[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        char mid = 0;
        vector<int> half(26, 0);
        int len = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                mid = 'a' + i;
            }
            half[i] = freq[i] / 2;
            len += half[i];
        }

        // Total possible valid distinct palindromic arrangements
        if (countWays(half, len) < k) {
            return "";
        }

        string first = "";
        first.reserve(len);

        // Digit-by-digit / position-by-position construction
        for (int pos = 0; pos < len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;
                long long ways = countWays(half, len - 1 - pos);

                if (ways >= k) {
                    first.push_back('a' + ch);
                    break; // Found the character for current position
                }

                k -= ways;
                half[ch]++; // Backtrack
            }
        }

        string second = first;
        reverse(second.begin(), second.end());

        if (mid != 0) {
            return first + mid + second;
        }

        return first + second;
    }
};