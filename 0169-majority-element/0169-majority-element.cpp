class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums.size();
        if (num == 1) {
            return nums[0];
        }
        int k = num/2;
        unordered_map<int,int> mp;
        for (int i = 0;i<nums.size();i++) {
            if (mp.find(nums[i]) != mp.end()) {
                if (mp[nums[i]] >= k) {
                    return nums[i];
                }
            } 
            mp[nums[i]]++;
        }
        for (auto e: mp) {
            if (e.second >= k) {
                return e.first;
            }
        }
        return -1;
    }
};