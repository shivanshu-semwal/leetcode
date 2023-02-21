class Solution {
public:
    
    int largestCombination(vector<int>& cd) {
        vector<bitset<32>> v;
        for(int &i:cd){
            v.push_back(bitset<32>(i));
        }
        
        vector<int> count(32, 0);
        for(bitset<32> &b: v){
            for(int i=0;i<32;i++){
                if(b[i]) count[i]++;
            }
        }
        
        return *max_element(count.begin(), count.end());
    }
};
