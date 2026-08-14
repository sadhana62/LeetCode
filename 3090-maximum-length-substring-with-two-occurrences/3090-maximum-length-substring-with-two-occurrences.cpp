class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        unordered_map<int,int> m;
        int maxLen = 0;
         int res = 0;    
        while (j < n) {
            m[s[j]]++;
            while (m[s[j]] > 2) {
                m[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};