class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if (n < k) {
            return -1;
        }
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int c = 0;
        double avg = (double)sum / k;
        if (avg >= threshold) {
            c++;
        }
        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];
            avg = (double)sum / k;

            if (avg >= threshold) {
                c++;
            }
        }

        return c;
    }
};