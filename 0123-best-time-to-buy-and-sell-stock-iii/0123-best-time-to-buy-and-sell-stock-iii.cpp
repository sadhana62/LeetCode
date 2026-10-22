
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> prev(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int k = 1; k <= 2; k++) {
                    if (j == 0) {
                        ahead[j][k] =
                            max(-prices[i] + prev[1][k], prev[0][k]);
                    } else {
                        ahead[j][k] = max(prices[i] + prev[0][k - 1],
                                          prev[1][k]);
                    }
                }
               
            }
            prev = ahead;
        }
        return prev[0][2];
    }
};
