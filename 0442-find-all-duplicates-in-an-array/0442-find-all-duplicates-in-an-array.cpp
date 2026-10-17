class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i <n ){
            int corr_ind = nums[i] - 1;
            if (nums[corr_ind] !=  nums[i]) {
                swap(nums[corr_ind],nums[i]);
            } else  {
                i++;
            }
        }
        vector<int> res;
        for (int i = 0;i<n;i++) {
            if (nums[i] != i+1) {
             res.push_back(nums[i]);
            }
        }
        return res;
    }
};