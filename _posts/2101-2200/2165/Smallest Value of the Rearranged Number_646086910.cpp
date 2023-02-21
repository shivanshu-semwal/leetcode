class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> nums(10, 0);
        bool neg = num < 0;
        if(neg) num  = -num;
        while(num>0){
            nums[num%10]++;
            num/=10;
        }
        if(neg){
            // sort by big
            long long  no=0;
            for(int i=9;i>=0;i--){
                while(nums[i]!=0){
                    no = no*10 + i;
                    nums[i]--;
                }
            }
            return -no;
        } else{
            // sort by small
            long long  no = 0;
            for(int i=1;i<=9;i++){
                if(nums[i]!=0){
                    no = i;
                    nums[i]--;
                    break;
                }
            }
            for(int i=0;i<=9;i++){
                while(nums[i]!=0){
                    no = no*10 + i;
                    nums[i]--;
                }
            }
            return no;
        }
    }
};
