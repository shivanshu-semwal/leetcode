class Solution {
public:
    string say(string s){
        string ans;
        for(int i=0;i<s.length();){
            int count = 1;
            char c = s[i++];
            while(i<s.length() && s[i]==c){
                count++;
                i++;
            }
            string temp = to_string(count);
            temp.push_back(c);
            ans.append(temp);
        }
        return ans;
    }
    
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans = say(countAndSay(n-1));
        //cout << ans << endl;
        return ans;
    }
};
