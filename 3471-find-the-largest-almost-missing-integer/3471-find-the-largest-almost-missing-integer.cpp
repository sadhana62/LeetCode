class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int lastStart = n - k;

        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);
        int ans = -1;

        for (auto& entry : pos) {
            int val = entry.first;
            auto& v = entry.second;

            int covered = 0;
            int curL = -1, curR = -2;

            for (int idx : v) {
                int L = max(0, idx - k + 1);
                int R = min(lastStart, idx);

                if (L > R)
                    continue;

                if (L > curR) {
                    covered += R - L + 1;
                    curL = L;
                    curR = R;
                } else if (R > curR) {
                    covered += R - curR;
                    curR = R;
                }
            }

            if (covered == 1)
                ans = max(ans, val);
        }

        return ans;
    }

}
;