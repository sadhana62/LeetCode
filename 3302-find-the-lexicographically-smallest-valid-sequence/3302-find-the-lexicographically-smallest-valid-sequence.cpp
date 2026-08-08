class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int i = word1.size()-1;
        int j = word2.size()-1;
        vector<int> last(word2.size(),-1);
        while (i >= 0 && j >=0) {
            if (word2[j] == word1[i]) {
                last[j] = i;
                j--;
                i--;
            } else {
                i--;
            }
        }
       bool noUse = false;
       j = 0;
       vector<int> ans;
       int m = word2.size();
        for (int i = 0;i<word1.size() && j< word2.size();i++) {
            if (word1[i] != word2[j]) {
               if (!noUse && (j == m-1 || i < last[j+1])) {
               noUse = true;
               ans.push_back(i);
               j++;
               }
            }
            else {
                ans.push_back(i);
                j++;
            }
        }
        if (j != m)
        return {};
        return ans;

    }
};