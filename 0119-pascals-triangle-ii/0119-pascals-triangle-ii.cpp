class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)
            return {};
        vector<vector<int>> res;
        vector<int> ind;
        if (rowIndex >= 0) {
            res.push_back({1});

            for (int i = 1; i <= rowIndex; i++) {
                vector<int> row;
                row.push_back({1});
                for (int j = 1; j < i; j++) {
                    row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
                row.push_back({1});
                res.push_back(row);
            }

           
        }

        return res[rowIndex];
    }
};