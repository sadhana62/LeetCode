class Solution {
private:
    // bool dfs(int col, vector<vector<int>>& graph, int node, int color[]) {
    //     color[node] = col;
    //     for (auto it : graph[node]) {
    //         if (color[it] == -1) {
    //             if (dfs(!col, graph, it, color) == false) {
    //                 return false;
    //             }
    //         } else if (color[it] == col) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    bool dfs(int c, int color[], int node, vector<vector<int>>& graph) {
        color[node] = c;
        for (auto ele : graph[node]) {
            if (color[ele] == -1) {
                if (dfs(!c, color, ele, graph) == false) {
                    return false;
                }
            } else if (color[ele] == c) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        // for (int i = 0; i < n; i++) {
        //     color[i] = -1;
        // }
        // for (int i = 0; i < n; i++) {
        //     if (color[i] == -1) {
        //         if (dfs(0, graph, i, color) == false) {
        //             return false;
        //         }
        //     }
        // }
        // return true;

        for (int i = 0; i < n; i++) {
            color[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(0, color, i, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};