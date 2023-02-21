class Solution {
public:    
    int trap(vector<int>& h) {
        int n = h.size(); 
        stack<int> s;    
        int ret = 0;       
        for(int i=0;i<n;i++){
            while(!s.empty() && h[s.top()] < h[i]){
                int j = s.top();
                s.pop();
                int width = 0;       
                int height = 0;
                if(!s.empty()){
                    if(h[s.top()] < h[i]){
                        height = h[s.top()] - h[j];
                    }
                    else{
                        height = h[i] - h[j];
                    }
                    width = i - s.top() - 1;
                }
                ret = ret + width * height;
            }
            s.push(i);
        }
        return ret;
    }
};
