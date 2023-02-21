class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int bal=1;
        int i=digits.size() - 1;
        while(i>=0 && bal){
            digits[i] += bal;
            bal = digits[i] / 10;
            digits[i] %= 10;
            i--;
        }
        if(bal) digits.insert(digits.begin(), 1);
        return digits;
    }
};
