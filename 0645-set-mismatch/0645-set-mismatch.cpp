class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
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
        for (int i = 0;i<n;i++) {
            if (nums[i] != i+1) {
              return {nums[i],i+1};
            }
        }
        return {-1,-1};
    }
};