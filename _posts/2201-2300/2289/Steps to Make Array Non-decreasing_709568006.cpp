class Solution {
public:
    int totalSteps(vector<int>& A) {
        int n = A.size(), res = 0;
        stack<pair<int, int>> st;
        st.push({A[0], 0});
        for(int i=0;i<n;i++){
            int t=0;
            while(!st.empty() && st.top().first <= A[i]){
                t = max(t, st.top().second);
                st.pop();
            }
            if(st.empty()) t = 0;
            else t++;
            st.push({A[i], t});
            res = max(res, t);
        }
        return res;
    }
};
