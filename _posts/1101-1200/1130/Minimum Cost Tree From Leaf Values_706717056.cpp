class Solution {
public:
    int dp[50][50];
    int solve(vector<int> &arr, int start, int end){
        // if(end-start==0) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        if(end-start==1) return 0;
        if(end-start==2){
            cout << "2: " << end << " " << start << endl;   
            return arr[start] * arr[start+1];
        }
        int ans = INT_MAX;
        for(int i=start+1;i<end;i++){
            int maxl = *max_element(arr.begin()+start, arr.begin()+i);
            int maxr = *max_element(arr.begin()+i, arr.begin()+end);
            int other = solve(arr, start, i) + solve(arr, i, end);
            cout << maxl << " " << maxr << " " << other << endl;
            ans = min(ans, maxl * maxr + other);
        }
        return dp[start][end]=ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof dp);
        int ans = INT_MAX;
        
        for(int i=1;i<n;i++){
            cout << "i:" << i << endl;
            int maxl = *max_element(arr.begin(), arr.begin() + i);
            int maxr = *max_element(arr.begin()+i, arr.end());
            int other = solve(arr, 0, i) + solve(arr, i, n);
            ans = min(ans, maxl * maxr + other);
            cout << ans << endl;
        }
        
        return ans;
    }
};
