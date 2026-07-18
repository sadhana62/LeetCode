class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) {
            return -1;
        }
        int sum = 0;
        for (int i = 0;i<k;i++) {
           sum+= nums[i];
        }
        double avg = (double)sum/k;
        double maxAvg = avg;
        cout<<"maxAvg "<<maxAvg;
        for (int i = k;i<n;i++) {
            sum+= nums[i] - nums[i-k];
            avg = (double)sum/k;
            maxAvg = max(maxAvg,avg);
        }
        return maxAvg;
    }
};