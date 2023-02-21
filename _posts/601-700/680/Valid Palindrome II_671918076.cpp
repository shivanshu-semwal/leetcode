class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int l=0, r=n-1;
        
        int c = 0;
        while(l<=r){
            if(s[l] != s[r]) {c++; l++;}
            else {l++; r--;}
        }
        // cout << c << endl;
        if(c<=1) return true;
        c = 0;
        l=0; r = n-1;
        while(l<=r){
            if(s[l] != s[r]) {c++; r--;}
            else {l++; r--;}
        }
        // cout << c << endl;
        if(c<=1) return true;
        
        return false;
    }
};

// abc
