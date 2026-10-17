class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n) {
            int corr_i = nums[i];
            if (corr_i < n && nums[i] != nums[corr_i]) {
                swap(nums[i],nums[corr_i]);
            } else {
                i++;
            }
        }
        for (int i = 0;i<n;i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};