struct Node {
    int maxLen = 0;       // Longest repeating substring length in this segment
    int prefixLen = 0;    // Length of repeating characters from left boundary
    int suffixLen = 0;    // Length of repeating characters from right boundary
    char firstChar = 0;   // Character at the left edge
    char lastChar = 0;    // Character at the right edge
    int length = 0;       // Total size of this segment
};

class Solution {
private:
    vector<Node> tree;

    // Merge logic: Combine two adjacent child nodes into a parent node
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.length = left.length + right.length;
        res.firstChar = left.firstChar;
        res.lastChar = right.lastChar;

        // Base max length is the best of either child
        res.maxLen = max(left.maxLen, right.maxLen);

        // 1. Cross-boundary check: Do adjacent characters match?
        if (left.lastChar == right.firstChar) {
            res.maxLen = max(res.maxLen, left.suffixLen + right.prefixLen);
        }

        // 2. Update Prefix Length
        res.prefixLen = left.prefixLen;
        if (left.prefixLen == left.length && left.lastChar == right.firstChar) {
            res.prefixLen += right.prefixLen;
        }

        // 3. Update Suffix Length
        res.suffixLen = right.suffixLen;
        if (right.suffixLen == right.length && left.lastChar == right.firstChar) {
            res.suffixLen += left.suffixLen;
        }

        return res;
    }

    // Build the initial Segment Tree from the original string
    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Update a single character at idx and re-balance the tree upwards
    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int q = queryIndices.size();
        tree.resize(4 * n);

        // Step 1: Build tree in O(N)
        build(1, 0, n - 1, s);

        vector<int> ans(q);

        // Step 2: Process each query in O(log N)
        for (int i = 0; i < q; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            
            // The root node (tree[1]) always holds the global maxLen for the full string
            ans[i] = tree[1].maxLen;
        }

        return ans;
    }
};