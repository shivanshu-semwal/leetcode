class Solution {
public:
    string convertToTitle(int c) {
        string s = "";
        while(c){
            cout << c << endl;
            int t = c%26;
   
            
            if(t==0) s.push_back('Z');
            else s.push_back('A' + t - 1);
            
            c /= 26;
            if(t==0) c--; 
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
