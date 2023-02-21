class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int bal=1;
        int i=digits.size() - 1;
        while(i>=0){
            if(digits[i] == 9){
                digits[i] = 0;
                bal = 1;
            }else{
                digits[i]++;
                return digits;
            }
            i--;
        }
        if(bal) digits.insert(digits.begin(), 1);
        return digits;
    }
};
