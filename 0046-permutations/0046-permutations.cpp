class Solution {
public:
    void solve(vector<int>& nums, vector<int>&out, vector<vector<int>>& res,vector<bool>& use) {
        if (out.size() == nums.size()) {
            res.push_back(out);
            return;
        }
        for (int k =0;k<nums.size();k++) {
            if(use[k]) continue;
            use[k] = true;
            out.push_back(nums[k]);
            solve(nums,out,res,use);
            out.pop_back();
            use[k]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>out;
        vector<bool>use(nums.size(),false);
        solve(nums,out,res,use);
        return res;
    }
};
