class KthLargest {
    int k;
    vector<int> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0;i<nums.size();i++) {
            this->nums.push_back(nums[i]);
        }
        sort(this->nums.begin(),this->nums.end());
    }
    int add(int val) {
        nums.push_back(val);
        int n = nums.size();
        int temp = nums[n-1];
        int i = n-1;
        int j = i-1;
        while(j >=0 && nums[j] > temp) {
            nums[j+1] = nums[j];
            j = j-1;
        }
        nums[j+1] = temp;
        return nums[n-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */