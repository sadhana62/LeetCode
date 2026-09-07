class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int iter = 1; iter < n; iter++) {
            string next = "";
            int i = 0;
            int len = result.size();
            
            while (i < len) {
                char digit = result[i];
                int count = 0;
                while (i < len && result[i] == digit) {
                    count++;
                    i++;
                }
                next += to_string(count) + digit;
            }
            
            result = next;
        }
        
        return result;
    }
};