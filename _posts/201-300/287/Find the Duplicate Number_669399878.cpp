class Solution {
public:
    int findDuplicate(vector<int>& a) {
        while(1){
            for(int i=0; i<a.size();i++){
                if(a[i] != i+1){
                    int temp = a[i];
                    if(a[a[i]-1] == a[i]) return a[i];
                    a[i] = a[a[i]-1];
                    a[temp-1] = temp;
                }
            }
        }
        return 0;
    }
};

