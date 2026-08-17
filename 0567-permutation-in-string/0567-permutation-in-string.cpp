class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> freq(256, 0);

        int n1 = s1.size();
        int n2 = s2.size();

        int c = 0;
        int l = 0;
        int r = 0;

        for (char ele : s1) {
            freq[ele]--;
        }

        while (r < n2) {

            // Add right character
            freq[s2[r]]++;
            r++;
            c++;

            // Window size == s1 size
            if (c == n1) {

                bool isAnagram = true;

                for (int i = 0; i < 256; i++) {
                    if (freq[i] != 0) {
                        isAnagram = false;
                        break;
                    }
                }

                if (isAnagram) {
                    return true;
                }

                // Slide the window
                freq[s2[l]]--;
                l++;
                c--;
            }
        }

        return false;
    }
};