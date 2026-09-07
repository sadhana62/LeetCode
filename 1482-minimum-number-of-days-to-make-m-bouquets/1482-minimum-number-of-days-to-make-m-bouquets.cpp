class Solution {
public:
    bool dayRequired(vector<int>& bloomDay, int m, int k,int days) {
        int c = 0;
        int noBouquet = 0;
        for (int i = 0;i<bloomDay.size();i++) {
            if (bloomDay[i] <= days) {
                c++;
                if (c == k) {
                    noBouquet++;
                    c =0;
                }
            } else {
                c = 0;
            }
        }
        return m<=noBouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n =  bloomDay.size();
        if (1LL*m*k > n) return -1;
        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int h = *max_element(bloomDay.begin(),bloomDay.end());
        while (l <= h) {
            long long mid = (l+h)/2;
            if (dayRequired(bloomDay,m,k,mid)) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;

    }
};