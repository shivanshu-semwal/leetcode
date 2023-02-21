class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        
        special.push_back(top+1);
        
        int m = INT_MIN;
        
        int prev = bottom - 1;
        
        for(int i=0;i<special.size();i++){
            int temp = special[i] - prev - 1;
            prev = special[i];
            m = max(m, temp);
        }
        
        return m;
    }
};
