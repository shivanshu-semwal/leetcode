bool comp(vector<int> &a, vector<int> &b){
    return (a[1] < b[1]);
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {      
        sort(courses.begin(), courses.end(), comp);
        int total = 0;
        
        priority_queue<int> pq;
        
        for(int i=0;i<courses.size();i++){
            int duration = courses[i][0];
            int end = courses[i][1];
            if( total + duration <= end){
                pq.push(duration);
                total += duration;
            } else if(!pq.empty() && pq.top() > duration){
                total += duration - pq.top();
                pq.pop();
                pq.push(duration);
            }
        }
        
        return pq.size();
    }
};
