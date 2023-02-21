class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        
        vector<int> even;
        vector<int> odd;
        
        for(int i=0;i<s.length();i++){
            int temp = s[i] - '0';
            if(temp&1) odd.push_back(temp);
            else even.push_back(temp);
        }
        
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        
        int ans = 0;
        int j=0, k=0;
        for(int i=0;i<s.length();i++){
            int temp = s[i] - '0';
            if(temp&1) ans = ans * 10 + odd[j++];
            else ans = ans * 10 + even[k++];
        }
        
        return ans;
    }
};
