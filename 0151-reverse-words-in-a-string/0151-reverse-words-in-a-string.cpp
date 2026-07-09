#include <string>

class Solution {
public:
    string reverseWords(string s) {
        // string word;
        // stringstream ws(s);
        // stack<string> st;
        // while (ws >> word) {
        //     st.push(word);
        // }
        // string out = "";
        // while (!st.empty()) {
        //     out += st.top();
        //     st.pop();
        //     if (!st.empty()) {
        //         out += " ";
        //     }
        // }
        // return out;
     string out = "";
    int i = s.size() - 1;

    while (i >= 0) {

        while (i >= 0 && s[i] == ' ')
            i--;

        if (i < 0)
            break;

        int end = i;

        while (i >= 0 && s[i] != ' ')
            i--;

        out += s.substr(i + 1, end - i);

        while (i >= 0 && s[i] == ' ')
            i--;

        if (i >= 0)
            out += ' ';
    }
return out;
    }
};