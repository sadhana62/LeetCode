class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
    > pq;
      vector<vector<int>> res;
      for (auto& ele : points) {
        int dis = ele[0]*ele[0]+ele[1]*ele[1];
        pq.push({dis,{ele[0],ele[1]}});
      } 
      if (pq.empty()) return {};
      
      while(!pq.empty()) {
        auto ele = pq.top();
        pq.pop();
        res.push_back({ele.second.first,ele.second.second});
        k--;
        if (k == 0) break;
      }
      return res;
    }
};
