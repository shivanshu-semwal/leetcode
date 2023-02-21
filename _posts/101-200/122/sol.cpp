class Solution {
public:
    int maxProfit(vector<int>& a) {
        int total = 0;
        int n = a.size();
        if(n==1) return 0;
        int buy=-1, sell=0;
        for(int i=0;i<n;i++){
            if(buy != -1){
                if(a[i-1] > a[i]){
                    total = total + (a[i-1] - buy);
                    buy = a[i];
                }
            } else {
                buy = a[i];
            }
        }
        if(buy != -1) total += a[n-1] - buy;
        return total;
    }
};
