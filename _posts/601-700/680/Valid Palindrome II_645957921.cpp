class Solution {
public:
    bool isvalid(string &s, int i, int j, int &count){
        int n = s.length();
        while(i<= n/2 && j >= n/2){
            if(s[i] == s[j]){
                j--;
                i++;
                //continue;
            } else {
                cout << i <<  " " << j << endl;
                cout << s[i] << " " << s[j] << endl;
                count++;
                if(count > 1) return false;
                //if(i+1>n/2 && j-1<n/2) return true;
                return isvalid(s, i+1, j, count) || 
                       isvalid(s, i, j-1, count);
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        if(n==1) return true;
        if(n==2) return true;
        int count = 0;
        return isvalid(s, 0, n-1, count);
    }
};
