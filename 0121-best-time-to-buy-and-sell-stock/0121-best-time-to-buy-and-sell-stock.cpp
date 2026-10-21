class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int miniprice = prices[0];
       int maxProfit = 0;
       for (int i =0;i<prices.size();i++) {
        if (prices[i]< miniprice) {
            miniprice = prices[i];
        }
        maxProfit = max(maxProfit,prices[i]-miniprice);

       } 
       return maxProfit;
    }
};