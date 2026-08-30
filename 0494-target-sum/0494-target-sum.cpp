class Solution {
public:
    int subsetSum(int i,int sum,vector<int>&nums,vector<vector<int>>& dp) {
        if (i == 0) {
            if (sum == 0 && nums[i] == 0) return 2;
            if (sum == 0 || nums[i] == sum) return 1;
            else return 0;
        }
        if (dp[i][sum] != -1) return dp[i][sum];
        int notTake = subsetSum(i-1,sum,nums,dp);
        int take = 0;
        if (sum >= nums[i]){
           take = subsetSum(i-1,sum-nums[i],nums,dp);
        }
        return dp[i][sum] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            totalSum += nums[i];
        }
        int m = (totalSum + target) /2;
        // cout<<(totalSum-target)%2; 
        //    if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0)
        // return 0;
        if ((totalSum+target)/2 <0) return 0;
        if ((totalSum+target)%2 != 0) return 0;
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return subsetSum(n-1,m,nums,dp);
        
       

    }
};