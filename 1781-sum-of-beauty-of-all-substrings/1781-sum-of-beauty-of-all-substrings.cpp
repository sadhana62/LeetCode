class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
       
        int sum = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxi = 0;
                int mini = INT_MAX;
                for (auto fr : freq) {
                    if (fr > 0) {
                        maxi = max(maxi, fr);
                        mini = min(mini, fr);
                    }
                }
                sum += maxi - mini;
            }
        }
        return sum;
    }
};