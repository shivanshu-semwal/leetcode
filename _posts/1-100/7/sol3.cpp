class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            cout << ans << endl;
            ans = ans*10 + x%10;
            x /= 10;
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10){
                //cout << ans << " " << INT_MIN << endl;
                if(x==0) return ans;
                else return 0;
            }
        }
        return ans;
    }
};
