class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> outDegree(n, 0);
      for (int i = 0; i < n; i++) {
            outDegree[i] = graph[i].size();

            for (auto it : graph[i]) {
                revGraph[it].push_back(i);
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int ele = q.front();
            q.pop();
            res.push_back(ele);
            for (auto el : revGraph[ele]) {
                outDegree[el]--;
                if (outDegree[el] == 0) {
                    q.push(el);
                }
            }
        }
        for (int i = 0;i<res.size();i++) {
            cout<<res[i];
        }
        sort(res.begin(),res.end());
        return res;
    }
};