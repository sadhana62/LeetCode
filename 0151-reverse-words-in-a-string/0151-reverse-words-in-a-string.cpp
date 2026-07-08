#include <string>

class Solution {
public:
    string reverseWords(string s) {
        string word;
        stringstream ws(s);
        stack<string> st;
        while (ws >> word) {
            st.push(word);
        }
        string out = "";
        while (!st.empty()) {
            out += st.top();
            st.pop();
            if (!st.empty()) {
                out += " ";
            }
        }
        return out;
    }
};