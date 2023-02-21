class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        // reminder will be from range 0 to K-1
        vector<int> count(K, 0);
        
        count[0] = 1;
        int p = 0;
        int ans = 0;
        for(int i=0;i<A.size();i++){
            p = (((A[i] + p) % K) + K) %K;
            ans = ans + count[p];
            count[p] += 1;
        }
        
        return ans;
    }
};
