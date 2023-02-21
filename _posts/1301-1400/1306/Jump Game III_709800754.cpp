vector<int> ar;
class Solution {
public:
    bool ans;
    void helper(int i){
        if( i <0 || i>= ar.size() || ans || ar[i] == -1) return;
        cout<<i<<" ";
        int val = ar[i];
        if(val == 0) {
            ans = true;
            return;
        }
        ar[i] = -1;
        helper(i-val);
        helper(i+val);
    }
    bool canReach(vector<int>& arr, int start) {
        ar = vector<int>(arr.begin(), arr.end());
        ans = false;
        helper(start);
        ans?cout<<"\nTrue":cout<<"\nFalse";
        return ans;
    }
};
