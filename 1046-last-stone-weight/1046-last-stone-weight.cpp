class Solution {
public:
    void insertThenode(vector<int>& stones, int ele) {
        stones.push_back(ele);

        int i = stones.size() - 1;

        while (i > 0 && stones[i - 1] > ele) {
            stones[i] = stones[i - 1];
            i--;
        }

        stones[i] = ele;
    }
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return stones[0];
        if (n == 2) {
            int ele1 = stones.back();
            stones.pop_back();
            int ele2 = stones.back();
            stones.pop_back();
            return abs(ele1 - ele2);
        }
        int ans = 0;
        while (stones.size() > 1) {

            int ele1 = stones.back();
            stones.pop_back();
            int ele2 = stones.back();
            stones.pop_back();
            ans = ele1 - ele2;
            if (ans != 0) {
                insertThenode(stones, ans);
            }
        }
        if (stones.size() == 0)
            return 0;
        else
            return stones[0];
    }
};