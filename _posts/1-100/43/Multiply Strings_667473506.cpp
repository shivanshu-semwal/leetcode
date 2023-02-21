class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length() > num2.length()) return multiply(num2, num1); 
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        vector<int> ans(num1.length(), 0);
        
        int c = 0, i, j, a;
        for(i=0;i<num1.length();i++){
            a = num1[i] - '0';
            if(a==0) continue;
            
            for(j=0;j<num2.length() && j+i < ans.size();j++){
                ans[j+i] += a * (num2[j]-'0') + c; 
                c = ans[j+i] / 10;
                ans[j+i] %= 10;
            }
            
            while(j<num2.length()){
                ans.push_back(a * (num2[j]-'0') + c); 
                c = ans.back() / 10;
                ans[ans.size() - 1] = ans.back() % 10;
                j++;
            }
            
            while(c){
                ans.push_back(c%10);
                c = c / 10;
            }
                    
            //for(int i=0;i<ans.size();i++) ans[i] += '0';
            //cout << string(ans.rbegin(), ans.rend()) << endl;
            //for(int i=0;i<ans.size();i++) ans[i] -= '0';
        }
        
        for(int i=0;i<ans.size();i++) ans[i] += '0';
        
        return string(ans.rbegin(), ans.rend());
    }
};
