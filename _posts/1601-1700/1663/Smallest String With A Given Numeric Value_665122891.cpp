class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char> ans(n, 'a');
        
        k-=n; // all a = 1
        
        int c=n-1;
        
        while(k){
            if(k>=26){ // if z can fit
                ans[c--] = 'z';
                k -= 25;
            } else {
                ans[c--] = k + 'a';
                break;
            }
        }
        return string(ans.begin(), ans.end());
    }
};
