class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return s;
        string rev = s;
        reverse(rev.begin(),rev.end());
        string str = s + '#' + rev;
        int len = 0;
        vector<int>lps(str.size(),0);
        int i = 0;
        while(i <  str.length()) {
            if (i>0 && str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                }else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int longSame = lps.back();
        string suffixToMirror = s.substr(longSame);
        reverse(suffixToMirror.begin(),suffixToMirror.end());
        return suffixToMirror+s;


    }
};