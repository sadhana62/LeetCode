class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] >= 1 && nums[i] <= n) {
                int corr_ind = nums[i] - 1;

                if (nums[corr_ind] != nums[i]) {
                    swap(nums[i], nums[corr_ind]);
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        int result = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};