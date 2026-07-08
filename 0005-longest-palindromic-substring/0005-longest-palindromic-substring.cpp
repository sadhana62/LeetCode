class Solution {
public:
    int palindrome(string s, int l, int h) {
        while(l>=0 && h<s.size() && s[l]==s[h]){
           l--;
           h++;
        }
        return h-l-1;
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int maxLen = 0;
        int start  = 0;
        int end = 0;
        for (int i = 0;i<s.size();i++) {
            int odd = palindrome(s,i,i);
            int even = palindrome(s,i,i+1);
            int l = max(odd,even);
            if (l > maxLen) {
                maxLen = l;
                start = i - (l-1)/2;
                end = i + (l/2);
            }
        }
        
        return s.substr(start,(end-start+1));
    }
};