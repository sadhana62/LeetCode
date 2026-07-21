class NumArray {
public:
    vector<vector<int>> arr;
    NumArray(vector<int>& nums) {
        arr.push_back(nums);
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left;i<=right;i++) {
            sum+=arr[0][i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */