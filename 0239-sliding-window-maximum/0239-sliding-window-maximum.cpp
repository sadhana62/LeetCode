class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int max = INT_MIN;
        vector<int> temp;
        deque<int> dq;
        // if (n < k) {
        //     for (int i = 0; i < n; i++) {
        //         if (nums[i] > max) {
        //             max = nums[i];
        //         }
        //     }
        //     return {max};
        // }
        // vector<int> temp;
        // int ele = *max_element(nums.begin(), nums.begin() + k);
        // temp.push_back(ele);
        // int j = 1;
        // for (int i = k; i < n; i++) {
        //     if (nums[j - 1] != temp.back()) {
        //         if (nums[i] > temp.back()) {
        //             temp.push_back(nums[i]);
        //         } else {
        //             int e = temp.back();
        //             temp.push_back(e);
        //         }
        //     } else {
        //         int maxEle = INT_MIN;
        //         for (int s = j; s <= i; s++) {
        //             if (nums[s] > maxEle) {
        //                 maxEle = nums[s];
        //             }
        //         }
        //         temp.push_back(maxEle);
        //     }

        //     j++;
        // }
        // return temp;
      
        for (int i =0;i<n;i++) {
            if (!dq.empty() && dq.front() <= i - k) {
                 dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
              temp.push_back(nums[dq.front()]);
            }
        }
        return temp;
        // vector<int> ans;
        // int n =  nums.size();
        // if (n < k) return {-1};
        // for (int i = 0;i<=n-k;i++) {
        //     int maxEle = nums[i];
        //     for (int j = i;j<i+k;j++) {
        //        maxEle = max(maxEle,nums[j]);
        //     }
        //     ans.push_back(maxEle);
        // }
        // return ans;
    }
};