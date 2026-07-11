class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0;i<n;i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1;j<n;j++) {
                 if (j > i+1 && nums[j] ==  nums[j-1]) continue;
                 int k = j+1;
                 int s = n-1;
                 while (k < s) {
                 long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[s];
                 if (sum == target)  {
                     vector<int> temp {nums[i],nums[k],nums[s],nums[j] };
                     ans.push_back(temp);
                     k++;
                     s--;
                     while (k<s && nums[k] == nums[k-1]) {
                        k++;
                     }
                      while (k<s && nums[s] == nums[s+1]) {
                        s--;
                     }
                 } else if (sum > target) {
                    s--;
                 } else {
                    k++;
                 }

                 }
            }
        }
        return ans;
         
    }
};