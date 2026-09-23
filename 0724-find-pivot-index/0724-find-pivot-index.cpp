class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>preSum(n);
        preSum[0] =  nums[0]; 
        for (int i = 1;i<n;i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }
        int total = preSum[n-1];
        int ind = -1;
        for (int i = 0;i<n;i++) {
            int leftSum = i == 0 ? 0 : preSum[i-1];
            int rightSum = total - preSum[i];
            if (leftSum == rightSum) {
              return i;
            }
        }
        return ind;
    }
};