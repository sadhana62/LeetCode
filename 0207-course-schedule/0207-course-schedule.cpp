class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDeg(numCourses,0);
        vector<int>adj[numCourses];
        queue<int>q;
        vector<int>topo;
        for (auto ele : prerequisites) {
            int preReq = ele[1];
            int nexReq = ele[0];
            adj[preReq].push_back(nexReq);
        }
        for (int i = 0;i<numCourses;i++) {
            for (auto ele : adj[i]){
                  inDeg[ele]++;
            }
        }
        for (int i = 0;i<numCourses;i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
     
        while (!q.empty()) {
            auto ele = q.front();
            cout<<ele;
            topo.push_back(ele);
            q.pop();
            for (auto a: adj[ele]) {
               inDeg[a]--;
               if (inDeg[a] == 0) {
                q.push(a);
               }
            }

        }

    if (topo.size() == numCourses) return true;
    else return false;
    }
};