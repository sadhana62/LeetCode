class Solution {
public:
    void fun( int i, string& digits, string& out, unordered_map<char,string>& mp,vector<string>& ans) {
        if (i  == digits.size()) {
           ans.push_back(out);
           return ;
        }
        string letter = mp[digits[i]];
        for (char ch : letter) {
            out.push_back(ch);
            fun(i+1,digits,out,mp,ans);
            out.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}

        };

        vector<string> ans;
        string out;
        int l = digits.size();
        fun(0,digits,out,mp,ans);
        return ans;

    }
};