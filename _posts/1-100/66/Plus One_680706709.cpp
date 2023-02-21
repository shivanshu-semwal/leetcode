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
        if(bal){
            vector<int> temp = {bal};
            temp.insert(temp.end(), digits.begin(), digits.end());
            return temp;
        }
        return digits;
    }
};
