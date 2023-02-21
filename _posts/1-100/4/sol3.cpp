class Solution {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int m = A.size(), n = B.size();
        if (m > n) return findMedianSortedArrays(B, A);

        int minidx = 0;
        int maxidx = m;
        int i, j;
        int num1, num2;
        int mid = (m + n + 1) / 2;

        cerr << "m: " << m << " n: " << n << "\n";
        cerr << "mid: " << mid << "\n";

        while (minidx <= maxidx) {
            cerr << "===================\n";
            cerr << "minidx: " << minidx << " maxidx: " << maxidx << "\n";

            i = (minidx + maxidx) / 2;
            j = mid - i;
            cerr << "i: " << i << " j: " << j << "\n";

            if (i < m && j > 0 && B[j - 1] > A[i]) {
                minidx = i + 1;
                cerr << "shift >> \n";
            } else if (i > 0 && j < n && B[j] < A[i - 1]) {
                maxidx = i - 1;
                cerr << "shift << \n";
            } else {
                if (i == 0)
                    num1 = B[j - 1];
                else if (j == 0)
                    num1 = A[i - 1];
                else
                    num1 = max(A[i - 1], B[j - 1]);
                break;
            }
        }
        if (((m + n) & 1)) {
            return num1;
        }
        if (i == m) { // all A elements are smaller than B
            num2 = B[j];
        } else if (j == n) { // all A elements are greater than B
            num2 = A[i];
        } else {
            num2 = min(A[i], B[j]);
        }
        return (num1 + num2) / 2.;
    }
};
