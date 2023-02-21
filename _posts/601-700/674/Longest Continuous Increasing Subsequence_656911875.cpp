class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int ans = 1, i=1, j;
        while(i<a.size()){
            int j=i;
            while(j < a.size() && a[j-1] < a[j]) j++;
            ans = max(ans, j-i+1);
            i = j+1;
        }
        return ans;
    }
};
