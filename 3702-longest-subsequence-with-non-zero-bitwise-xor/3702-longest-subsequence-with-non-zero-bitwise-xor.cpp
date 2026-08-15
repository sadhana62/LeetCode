class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int total_xor = 0;
        bool has_non_zero = false;

        for (int x : nums) {
            total_xor ^= x;
            if (x != 0) {
                has_non_zero = true;
            }
        }

        // If total XOR is non-zero, take all elements
        if (total_xor != 0) return nums.size();

        // If total XOR is zero, remove any one non-zero element
        if (has_non_zero) return nums.size() - 1;

        // If all elements are 0, no valid subsequence exists
        return 0;


    }
};