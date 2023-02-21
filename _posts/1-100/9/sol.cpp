class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        else{
            long rev = 0;
            long n = x;
            while(n > 0){ rev = rev * 10 + (n%10); n/=10; }
            if(rev == x) return true;
            else return false;
        }
        
    }
};
