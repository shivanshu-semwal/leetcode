class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> pq(less<int>(), nums);
        int ans; 
        int a = pq.top(); pq.pop();
        
        ans = a;
        ans *= pq.top(); pq.pop();
        ans *= pq.top(); pq.pop();
        
        priority_queue<int, vector<int>, greater<int>> p(greater<int>(), nums);
        
        int ans1 = p.top(); p.pop();
        ans1 *= p.top(); p.pop();
        ans1 *= a;
        
        return max(ans, ans1);
    }
};
