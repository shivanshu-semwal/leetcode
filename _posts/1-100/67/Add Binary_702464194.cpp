class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int i=0, c=0;
        while(i<a.length() && i<b.length()){
            ans.push_back(a[i] - '0' + b[i] - '0' + c);
            if(ans[i]==2){
                ans[i] = '0';
                c = 1;
            } else if(ans[i] ==3){
                ans[i] = '1';
                c = 1;
            } else {
                ans[i] = ans[i] + '0';
                c = 0;
            }
            i++;
        }
        while(i<a.length()){
            ans.push_back(a[i] - '0' + c);
            if(ans[i]==2){ ans[i] = '0'; c = 1; } 
            else if(ans[i] ==3){ ans[i] = '1'; c = 1; }
            else { ans[i] = ans[i] + '0'; c = 0; }
            i++;
        }
        while(i<b.length()){
            ans.push_back(b[i] - '0' + c);
            if(ans[i]==2){ ans[i] = '0'; c = 1; } 
            else if(ans[i] ==3){ ans[i] = '1'; c = 1; }
            else { ans[i] = ans[i] + '0'; c = 0; }
            i++;
        }
        if(c) ans.push_back('0' + c);
        reverse(ans.begin(), ans.end());
        return string(ans.begin(), ans.end());
    }
};
