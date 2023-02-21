class Solution {
public:
    int countOperations(int num1, int num2, int ans=0) {
        if(num1==0 || num2==0) return ans;
        if(num1 > num2) return countOperations(num1%num2, num2, ans + num1/num2);
        else return countOperations(num2%num1, num1, ans + num2/num1);
    }
};
