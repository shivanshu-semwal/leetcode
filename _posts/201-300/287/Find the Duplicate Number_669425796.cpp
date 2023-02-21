class Solution {
public:
    int findDuplicate(vector<int>& a) {
        for(int i=0;i<a.size();i++){
            if(a[abs(a[i])] < 0){
                return abs(a[i]);
            } else {
                a[abs(a[i])] *= -1;
            }
        }
        
        return 0;
    }
};

// 1 2 3 4 5 
// 1 2 3 4 4
// 1 2 3 3 4
// 1 2 2 3 4
// 1 1 2 3 4

// 
