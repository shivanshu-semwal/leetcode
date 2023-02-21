class Solution {
public:
    bool find132pattern(vector<int>& v) {
        int s1, s2, s3;
        
        stack<int> st;
        
        s3 = INT_MIN;
        for(int i=v.size()-1;i>=0;i--){
            
            if(v[i] < s3){
                return true;
            } else{
                while(!st.empty() && v[i] > st.top()){
                    s3 = st.top();
                    st.pop();
                }
            }
            st.push(v[i]);
            
        }
        
        return false;
    }
};
