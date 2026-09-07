class Solution {
public:
    int countPalindromes(string s) {
         int n = s.size();
        const long long MOD = 1e9 + 7;

        // suffixPairs[i][b][a] = count of pairs (b then a) using indices strictly > i
        vector<array<array<long long,10>,10>> suffixPairs(n);
        array<long long,10> cnt1{};
        array<array<long long,10>,10> cnt2{};

        for (int i = n - 1; i >= 0; i--) {
            suffixPairs[i] = cnt2; // snapshot BEFORE including index i
            int x = s[i] - '0';
            for (int d = 0; d < 10; d++) cnt2[x][d] += cnt1[d];
            cnt1[x] += 1;
        }

        long long ans = 0;
        array<long long,10> cnt1f{};
        array<array<long long,10>,10> cnt2f{}; // pairs (a then b) using indices strictly < i

        for (int i = 0; i < n; i++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    if (cnt2f[a][b] == 0) continue;
                ans = (ans + cnt2f[a][b] * suffixPairs[i][b][a]) % MOD;
                }
            }
            int x = s[i] - '0';
            for (int d = 0; d < 10; d++) cnt2f[d][x] += cnt1f[d];
            cnt1f[x] += 1;
        }

        return (int)(ans % MOD);
    }
};