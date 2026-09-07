class Solution {
public:
    struct TrieNode {
        TrieNode* child[2] = {nullptr, nullptr};
    };
    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 29; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int query(int x) {
        TrieNode* node = root;
        if (!node->child[0] && !node->child[1]) return -1; // trie empty
        int result = 0;
        for (int i = 29; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = 1 - bit;
            if (node->child[want]) {
                result |= (1 << i);
                node = node->child[want];
            } else {
                node = node->child[bit];
            }
        }
        return result;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n = queries.size();
        vector<int> answer(n);
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a][1] < queries[b][1];
        });

        int j = 0, m = nums.size();
        for (int i : idx) {
            int x = queries[i][0], mi = queries[i][1];
            while (j < m && nums[j] <= mi) {
                insert(nums[j]);
                j++;
            }
            answer[i] = query(x);
        }
        return answer;
    }
};