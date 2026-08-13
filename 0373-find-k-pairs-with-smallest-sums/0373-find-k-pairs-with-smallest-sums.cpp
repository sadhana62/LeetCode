#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) return ans;

        int n1 = nums1.size();
        int n2 = nums2.size();

        // Tuple: {sum, {i, j}}
        typedef pair<int, pair<int, int>> P;
        priority_queue<P, vector<P>, greater<P>> min_heap;

        set<pair<int, int>> visited;

        // Push starting node (0, 0)
        min_heap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        while (k > 0 && !min_heap.empty()) {
            auto ele = min_heap.top();
            min_heap.pop();

            int i = ele.second.first;
            int j = ele.second.second;

            // Save answer pair
            ans.push_back({nums1[i], nums2[j]});
            k--;

            // Option 1: Move right in nums2 -> (i, j + 1)
            if (j + 1 < n2 && visited.find({i, j + 1}) == visited.end()) {
                min_heap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }

            // Option 2: Move down in nums1 -> (i + 1, j)
            if (i + 1 < n1 && visited.find({i + 1, j}) == visited.end()) {
                min_heap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
        }

        return ans;
    }
};