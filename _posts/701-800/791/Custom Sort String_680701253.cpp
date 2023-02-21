vector<int> rorder;
bool comp(const char &a, const char &b){
    if(rorder[a - 'a'] == rorder[b - 'a']) return a<b;
    return rorder[a - 'a'] < rorder[b - 'a'];
}

class Solution {
public:
    string customSortString(string order, string s) {
        if(order=="") return s;
        
        rorder = vector<int>(26, 0);
        for(int i=0;i<26;i++) rorder[i] = i + 1;
        
        vector<int> temp(order.length(), 0);
        temp[0] = rorder[order[0] - 'a'];
        
        for(int i=1;i<order.length();i++){
            rorder[order[i] - 'a'] += temp[i-1];
            temp[i] = max(temp[i-1], rorder[order[i] - 'a']);
        }
        
        // for(int i=0; i<26;i++){
        //     cout << i << " " << rorder[i] << endl;
        // }
        
        sort(s.begin(), s.end(), comp);
        return s;
    }
};
