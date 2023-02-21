class Solution {
public:
    
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n,0);
        vector<int> maxRight(n,0);
        
        int max = 0;
        for(int i=0;i<n;i++){
            maxLeft[i] = max;
            if(max < height[i]){
                max = height[i];
            }
        }
        
        max=0;
        for(int i=n-1;i>=0;i--){
            maxRight[i] = max;
            if(max < height[i]){
                max = height[i];
            }
        }
        
        int sum = 0;
        for(int i=1;i<n-1;i++){
            int level = (maxRight[i] < maxLeft[i]) ? maxRight[i] : maxLeft[i];
            if(level > height[i]){
                sum += (level - height[i]); 
            }
        }
        return sum;
    }
};
