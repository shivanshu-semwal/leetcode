class Solution {
public:
    int bs(vector<int> &a, int target, int start, int end){
        cout << start << " " << end << endl;
        if(start > end) return -1;
        int mid = start + (end - start)/2;
        if(a[mid] == target) return mid;
        
        if(a[start] <= a[mid]){
            if(a[start] <= target && target < a[mid]) 
                return bs(a, target, start, end-1);
            else 
                return bs(a, target, mid+1, end);
        } else {
            if(a[mid] < target && target < a[start])
                return bs(a, target, mid+1, end);
            else
                return bs(a, target, start, mid -1);
        }        
    }
    
    int search(vector<int>& a, int target) {
        return bs(a, target, 0, a.size() -1);
    }
};
