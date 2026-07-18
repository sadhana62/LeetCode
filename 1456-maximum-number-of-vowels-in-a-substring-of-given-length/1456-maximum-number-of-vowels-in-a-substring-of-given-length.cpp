class Solution {
public:
    bool isPresent (char ch) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
      else return false;   
    }
    int maxVowels(string s, int k) {
        int c = 0;
        int n =  s.size();
        if (n < k) return -1;
        for (int i =0; i<k;i++) {
            if (isPresent(s[i])){
                c++;
            }
        }
        int maxCount = c;
        for (int i = k; i<n;i++) {
            if (isPresent(s[i])){
                c = c+1;
            }
            if (isPresent(s[i-k])) {
                c = c-1;
            }
            if (i == 5) cout<<c;
            maxCount = max(c,maxCount);

        }
        return maxCount;
    }
};