class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxLen = 0;
        unordered_map<int,int> mp;
        while (r < n) {
            mp[nums[r]]++;
            while (mp[nums[r]] > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(mp[nums[l]]);
                }
              l++;
            }
              maxLen = max(maxLen,r-l+1);
              r++;
        }
        return maxLen;
    }
};
