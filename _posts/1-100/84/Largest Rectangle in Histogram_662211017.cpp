class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ret = 0;
        stack<int> mono;
        
        h.push_back(0);
        
        for(int i=0;i<h.size(); i++){
            while(!mono.empty() && h[mono.top()] > h[i]){
                int height = h[mono.top()];
                mono.pop();
                int length = (mono.empty()) ? i : (i - mono.top() - 1);
                ret = max(ret, height * length);
                //cout << height * length << endl;
            }
            mono.push(i);
        }
        
        return ret;
    }
};
