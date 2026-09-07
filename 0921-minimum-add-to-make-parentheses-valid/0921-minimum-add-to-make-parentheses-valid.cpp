class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;   // unmatched open parens so far
        int additions = 0; // insertions needed for unmatched close parens
        
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else { // c == ')'
                if (balance > 0) {
                    balance--; // matched
                } else {
                    additions++; // no open to match, needs an insertion
                }
            }
        }
        
        return additions + balance; // unmatched closes + leftover unmatched opens
    }
};