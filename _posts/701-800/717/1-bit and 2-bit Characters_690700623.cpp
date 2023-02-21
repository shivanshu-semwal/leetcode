class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ans = false;
        for(int i=0;i<bits.size();i++){
            if(bits[i]==1){
                i++;
                ans = false;
            } else{
                ans = true;
            }
        }
        return ans;
    }
};
