class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged(n + m);
        int i = 0, j = 0, k = 0;

        while (j < n && k < m) {
            if (nums1[j] < nums2[k]) {
                merged[i] = nums1[j++];
            } else {
                merged[i] = nums2[k++];
            }
            i++;
        }

        while (j < n) {
            merged[i] = nums1[j++];
            i++;
        }

        while (k < m) {
            merged[i] = nums2[k++];
            i++;
        }

        int mid = (n + m) / 2;
        if ((n + m) % 2 == 0) {
            double ans = (merged[mid - 1] + merged[mid]) / 2.0;
            return ans;
        } else {
            return merged[mid];
        }
    }
};
