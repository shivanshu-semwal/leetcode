

int romanToInt(char * s){
    int ans=0;
    int prev = 999999;

    for(int i=0;i<strlen(s);i++){
        int new=0;
        
        char c = s[i];
        if(c == 'M'){
            new = 1000;
        } else if(c == 'D'){
            new = 500;
        } else if(c== 'C'){
            new = 100;
        } else if(c =='L'){
            new = 50;
        } else if(c== 'X'){
            new = 10;
        } else if(c=='V'){
            new = 5;
        } else if(c=='I'){
            new = 1;
        }
        
        if(new > prev){
            ans = ans + new - prev - prev;
        } else{
            ans = ans + new;
        }
        prev = new;
    }
    return ans;
}
