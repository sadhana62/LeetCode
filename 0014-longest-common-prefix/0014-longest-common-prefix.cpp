class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string firstword = strs[0];
        string lastword = strs.back();
        string out = "";
        for (int i =0;i<lastword.size();i++) {
           if (firstword[i] == lastword[i]) {
            out += firstword[i];
           } else {
            break;
           }
        }
        return out;

    }
};