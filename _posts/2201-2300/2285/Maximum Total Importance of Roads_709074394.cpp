class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> arr(n+1, 0);
        
        for(auto i:roads){
            arr[i[0]]++;
            arr[i[1]]++;
        }
        sort(arr.begin(), arr.end(), greater<int>());
        long long int ans = 0;
        long long int N = n;       
        for(int i=0;i<=n;i++){
            ans += arr[i] * (N--);
        }
        return ans;
        
    }
};
