class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 0;
        int n = nums.size();
        if (n <=0) return -1;
        else if (n == 1) return 1;
        else {
            for (int i = 1;i<n;i++) {
                if (nums[i-1] != nums[i]) {
                    ind++;
                    cout<<"inside the if";
                    nums[ind] = nums[i];
                }
            }
            return ind+1;
        }
    }
};