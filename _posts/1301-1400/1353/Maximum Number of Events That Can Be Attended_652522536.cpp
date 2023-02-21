class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        sort(e.begin(), e.end());
        
        int total_days = e[0][1];
        for(auto i:e) if(i[1] > total_days) total_days = i[1];
        
        priority_queue<int, vector<int>, greater<int>> heap;
        
        int day = 0;
        int c = 0;
        int event = 1;
        int i = 0;
        
        
        while(day <= total_days){
            
            if(i < e.size() && heap.empty()){
                day = e[i][0];    
            }
            
            while(i < e.size() && e[i][0] <= day){
                heap.push(e[i][1]);
                i++;
            }
            
            while(!heap.empty() && heap.top() < day) heap.pop();
            
            if(!heap.empty()){
                heap.pop();
                c++;
            } else if(event >= e.size()){
                break;
            }
            
            day++;
        }
        
        return c;
    }
};
