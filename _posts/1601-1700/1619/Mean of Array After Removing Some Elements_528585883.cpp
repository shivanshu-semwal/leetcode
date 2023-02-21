class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int x = arr.size() / 20;
        double sum = accumulate(arr.begin() + x, arr.end() - x, 0);
        sum = sum / (arr.size() - 2 * x);
        return sum;
    }
};
