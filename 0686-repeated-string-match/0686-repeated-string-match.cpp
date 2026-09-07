class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string repeated = a;
        
        // Repeat 'a' until it's at least as long as 'b'
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }
        
        // Check current length; if not found, try one more repetition
        if (rabinKarpContains(repeated, b)) return count;
        
        repeated += a;
        count++;
        if (rabinKarpContains(repeated, b)) return count;
        
        return -1;
    }
    
private:
    bool rabinKarpContains(const string& text, const string& pattern) {
        int n = text.size(), m = pattern.size();
        if (m > n) return false;
        
        const long long BASE = 26, MOD = 1e9 + 7;
        long long patternHash = 0, windowHash = 0, power = 1;
        
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * BASE + (pattern[i] - 'a')) % MOD;
            windowHash = (windowHash * BASE + (text[i] - 'a')) % MOD;
            if (i > 0) power = (power * BASE) % MOD;
        }
        
        for (int i = 0; i <= n - m; i++) {
            if (windowHash == patternHash && text.substr(i, m) == pattern) {
                return true; // verify to avoid hash collision false positives
            }
            if (i < n - m) {
                windowHash = ((windowHash - (text[i] - 'a') * power % MOD + MOD) % MOD * BASE 
                              + (text[i + m] - 'a')) % MOD;
            }
        }
        return false;
    }
};