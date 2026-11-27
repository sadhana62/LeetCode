class Solution {
public:
    void dfs(int i, int j,
             vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = '0';
        stack<pair<int, int>> st;
        st.push({i, j});
        while (!st.empty()) {
            auto eleTop = st.top();
            st.pop();
            int i = eleTop.first;
            int j = eleTop.second;
            int row[4] = {-1, 0, 1, 0};
            int col[4] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++) {
                int newRow = i + row[k];
                int newCol = j + col[k];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == '1') {
                    grid[newRow][newCol] = '0';
                    st.push({newRow, newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> visit(n, vector<int>(m, 0));
        int no = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i,j,grid);
                    no = no + 1;
                }
            }
        }
        return no;
    }
};