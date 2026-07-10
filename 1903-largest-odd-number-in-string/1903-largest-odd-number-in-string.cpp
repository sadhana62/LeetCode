class Solution {
public:
    string largestOddNumber(string num) {
        string out="";
        int n = num.size()-1 ;
        int ind = -1;
        for (int i = n;i>=0;i--) {
            int digit = num[i]-'0';
            if (digit%2 != 0) {
                ind = i;
                break;
            }

        }
        if (ind == -1) return "";
        else return num.substr(0,ind+1);
    }
};