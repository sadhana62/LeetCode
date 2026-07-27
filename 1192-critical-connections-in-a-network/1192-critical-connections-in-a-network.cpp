class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, int low[], int tin[], vector<int> adj[],
             vector<vector<int>>& output, vector<int>& vis) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto n : adj[node]) {
            if (n == parent)
                continue;
            if (vis[n] == 0) {
                dfs(n, node, low, tin, adj, output, vis);
                low[node] = min(low[n], low[node]);
                if (low[n] > tin[node]) {
                    output.push_back({n, node});
                }

            } else {
                low[node] = min(low[n], low[node]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> vis(n, 0);
        int low[n];
        int tin[n];
        vector<vector<int>> output;
        for (auto ele : connections) {
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }

        dfs(0,-1,low,tin,adj,output,vis);
        return output;
    }
};