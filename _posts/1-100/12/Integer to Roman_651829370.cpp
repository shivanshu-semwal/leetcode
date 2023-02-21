class Solution {
public:
    string intToRoman(int n) {
        vector<pair<int, char>> con = { 
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        string ans="";
        
        while(n >= 1000){ ans += 'M'; n -= 1000;} if(n==0) return ans;
        while(n >= 900){ ans += "CM"; n -= 900;} if(n==0) return ans;
        while(n >= 500){ ans += "D"; n -= 500;} if(n==0) return ans;
        while(n >= 400){ ans += "CD"; n -= 400;} if(n==0) return ans;
        while(n >= 100){ ans += "C"; n -= 100;} if(n==0) return ans; 
        while(n >= 90){ ans += "XC"; n -= 90;} if(n==0) return ans;
        while(n >= 50){ ans += "L"; n-= 50;} if(n==0) return ans; 
        while(n >= 40){ ans += "XL"; n-= 40;} if(n==0) return ans;
        while(n >= 10){ans += "X"; n-=10;} if(n==0) return ans; 
        while(n >= 9){ans += "IX"; n -= 9;} if(n==0) return ans; 
        while(n >= 5){ans += "V"; n-= 5;} if(n==0) return ans;
        while(n >= 4){ans += "IV"; n -= 4;} if(n==0) return ans; 
        while(n >= 1){ans += "I"; n-=1;}
        return ans;
    }
};
