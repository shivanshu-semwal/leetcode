

int reverse(int x){
        int res = 0;
        while(x){
            if(res*10L + x%10L > INT_MAX || res*10L + x%10L < INT_MIN )
                return 0;
            // if(res > INT_MAX/10 || res < INT_MIN/10)
            res = res*10 + x%10;
            x /= 10; 
        }
        return res;
}
