class Solution {
public:
    void solve(int i,vector<vector<int>>& res,vector<int>out,vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back((out));
            return;
        }
        out.push_back(nums[i]);
        solve(i+1,res,out,nums);
        out.pop_back();
        solve(i+1,res,out,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>out;
        solve(0,res,out,nums);
        return res;
    }
};
