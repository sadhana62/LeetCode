class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = 0;
        // int j = 0;    
        // vector<int> temp;
        // while (i <m && j <n) {
        //    if (nums1[i] < nums2[j]) {
        //      temp.push_back(nums1[i]);
        //      i++;
        //    } else {
        //      temp.push_back(nums2[j]);
        //      j++;
        //    }
        // }
        // while (i<m) {
        //      temp.push_back(nums1[i]);
        //      i++;
        // }
        // while (j<n) {
        //      temp.push_back(nums2[j]);
        //      j++;
        // }
        // for (int i = 0;i<m+n;i++) {
        //     nums1[i] = temp[i];
        // }
       
       int len = m + n;
       int gap = len/2+ len%2;
       while (gap > 0) {
         int i = 0;
         int j = gap;
         while (j < len) {
            // case 1 both gap lies in the arr1 itself ;
            if (i< m && j <m) {
            if (nums1[i] > nums1[j]) {
                swap(nums1[i],nums1[j]);
            }

            }
            // case 2 if gap lies in arr2 
            else if (i < m && j>=m) {
                if (nums1[i] > nums2[j-m]) {
                    swap(nums1[i],nums2[j-m]);
                }

            } else {
                if (nums2[i-m] > nums2[j-m]) {
                    swap(nums2[i-m],nums2[j-m]);
                }
            }
            i++;
            j++;
         }
         if (gap == 1) break;
         gap = gap/2 + gap%2;
       }
         for (int k = 0; k < n; k++) {
            nums1[m + k] = nums2[k];
        }

    }
};