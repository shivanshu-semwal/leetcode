class Solution {
public:
    int inline getLength(vector<int>& p1, vector<int>& p2){
        return (p1[0]-p2[0]) * (p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]);
    }
    
    bool valid(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> a;
        a.push_back(getLength(p1, p2));
        a.push_back(getLength(p1, p3));
        a.push_back(getLength(p1, p4));
        sort(a.begin(), a.end());
        if(a[0]==0) return false;
        if(a[0]!=a[1]) return false;
        if(2*a[0] != a[2]) return false;     
        return true;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return valid(p1, p2, p3, p4) && valid(p2, p1, p3, p4) && valid(p3, p1, p2, p4) &&
            valid(p4, p1, p2, p3);
    }
};
