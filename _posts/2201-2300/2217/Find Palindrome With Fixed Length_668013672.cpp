class Solution {
public:
    long long rev(long long n){
        long long rev=0;
        while(n){
            rev = rev * 10 + n%10;
            n/=10;
        }
        return rev;
    }
    
    vector<long long> kthPalindrome(vector<int>& q, int n) {
        vector<long long> ans;
        if(n%2==0){
            long long p = (n/2) - 1;
            long long start = pow(10L, p);
            long long end = start * 10;
            for(int i=0;i<q.size();i++){
                long long x = start - 1L + q[i];
                if(x<end){
                    x = x*end + rev(x);
                    ans.push_back(x);
                } else {
                    ans.push_back(-1L);
                }
            }
        } else{
            long long p = ((n+1)/2) - 1;
            long long start = pow(10L, p);
            long long end = start * 10;
            
            for(int i=0;i<q.size();i++){
                long long x = start - 1L + q[i];
                if(x<end){
                    x = (x/10L)*end + rev(x);
                    ans.push_back(x);
                } else {
                    ans.push_back(-1L);
                }
            }    
        }
        
        return ans;
    }
};
