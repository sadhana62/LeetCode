class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //   int n = nums.size();
        //   if (n == 0) return 0;
        //   if (n == 1)  return 1;
        //   sort(nums.begin(), nums.end());
        //   int maxLen = 1;
        //   int c = 1;
        //   for (int i = 1;i<nums.size();i++) {

        //       if (nums[i] == nums[i-1])
        //       continue;

        //       if (nums[i] == nums[i-1] +1) {
        //         c++;
        //       } else {
        //       maxLen = max(maxLen,c);
        //       c = 1;
        //       }

        //   }
        //   return max(maxLen,c);
        unordered_set<int> st(nums.begin(), nums.end());
        int max_strike = 0;
        for (auto num : st) {
            if (st.find(num - 1) == st.end()) {
                int current_num = num;
                int current_strike = 1;
                while (st.find(current_num + 1) != st.end()) {
                    current_num++;
                    current_strike++;
                }
                max_strike = max(max_strike, current_strike);
            }
        }
        return max_strike;
    }
};