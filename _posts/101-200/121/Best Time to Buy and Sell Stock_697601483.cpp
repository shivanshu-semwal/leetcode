class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> m;
        int n = prices.size();
        int mprice = -1;
        for(int i=n-1;i >= 0;i--){
            if(prices[i] > mprice) mprice = prices[i];
            m.push_back(mprice);
        }
        // for(auto i:m) cout << i << " ";
        // 4 6 6 6 6 7
        // 7 1 5 3 6 4
        
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(m[n - i - 2] - prices[i] >  ans) 
                ans = m[prices.size() - i - 1] - prices[i];
        }
        
        return ans;
    }
};
