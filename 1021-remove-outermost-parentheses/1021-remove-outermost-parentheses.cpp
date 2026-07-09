class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth =  0;
        string output = "";
        for (char ch:s) {
            if (ch == '(') {
                if (depth>0) output+=ch;
                depth++;
            } else {
                depth--;
                if(depth > 0) {
                    output+=ch;
                }
            }
        }
        return output;
    }
};