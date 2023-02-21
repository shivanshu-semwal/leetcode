class Solution {
public:
    std::string trim(const std::string& str){
        int start, len;
        for (start = 0; start < str.size() && str[start] == ' '; start++);
        for (len = str.size() - start; len > 0 && str[start + len - 1] == ' '; len--);
        return str.substr(start, len);
    }
    bool isDigit(char c){return c<='9' && c>='0';}
    
    int myAtoi(string s) {
    
        int j=0;
        s = trim(s);
        int n = s.length();
        bool neg = false;     
        if(s[j]=='-'){ neg = true; j++;}
        else if(s[j]=='+'){ neg = false; j++;}
     
        if(j>=n) return 0;
        long no=0;      
        while(j<n){
            cout << s[j] << endl;
            if(isDigit(s[j])){
                cout << "no: " << no << endl;
                no = no * 10L + (s[j] - '0');
            } else {
                break;
            }
            if(no > INT_MAX){
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
            j++;
        }
        
        if(neg) no = -1L * no;

        return no;
    }
};
