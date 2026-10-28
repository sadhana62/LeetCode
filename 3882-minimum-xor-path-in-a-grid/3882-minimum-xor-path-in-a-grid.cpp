class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;
    
    int compute(int i,int j , int k, vector<vector<int>>& grid) {
        if (i>= n || j >= m) {
            return INT_MAX;
        }
        k ^= grid[i][j];
        if (i == n-1 && j == m -1) {
            return k;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int right = compute(i+1,j,k,grid);
        int down = compute(i,j+1,k,grid);
        return dp[i][j][k] = min(right,down);
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(m, vector<int>(1024,-1)));
        return compute(0,0,0,grid);
    }
};