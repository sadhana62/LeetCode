class Solution {
public:
    void solve(int idx,string s, vector<vector<string>>& res, vector<string>&out) {
        if (idx == s.size()) {
            res.push_back(out);
            return;
        }
        for (int i = idx;i<s.size();i++) {
           if (isPalindrome(s,idx,i)) {
              out.push_back(s.substr(idx,i-idx+1));
              solve(i+1,s,res,out);
              out.pop_back();
           }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
          if(s[start++] != s[end--]) return false; 
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        solve(0,s,res,out);
        return res;
    }
};
