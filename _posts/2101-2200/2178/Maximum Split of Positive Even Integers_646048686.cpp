class Solution {
public:
    vector<long long> maximumEvenSplit(long long x) {
        if(x&1) return vector<long long>();
        x /= 2;
        vector<long long> ans;
        long long sum=0;
        long long i=1;
        while(sum < x){
            sum += i;
            ans.push_back(i);
            i++;
        }
        if(sum > x){
            sum -= ans.back();
            ans.pop_back();
            ans[ans.size()-1] += x - sum;
        }
        
        for(i=0;i<ans.size();i++){
            ans[i] <<= 1;
        }
        return ans;
    }
};
