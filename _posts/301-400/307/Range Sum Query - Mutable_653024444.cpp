class NumArray {
public:
    
    // st - segiment tree
    // ss - segiment start
    // se - segiment end
    // si - segiment index
    
    vector<int> arr;
    vector<int> st;
    
    int make(int ss, int se, int si){
        if(ss == se){ // only one element remain
            st[si] = arr[ss];
            return arr[ss];
        }
        int mid = ss + (se - ss)/2;
        st[si] = make(ss, mid, si*2 + 1) + make(mid + 1, se, si*2 + 2);
        return st[si];
    }
    
    NumArray(vector<int>& nums) {
        arr = nums;
        int x = (int)(ceil(log2(nums.size())));
        int max_size = 2 * (int) pow(2, x) - 1;
        st = vector<int>(max_size, 0);
        make(0, arr.size() - 1, 0);
    }
    
    void updateUtil(int ss, int se, int index, int diff, int si){
        if(index < ss || index > se) return;
        st[si] = st[si] + diff;
        if(ss != se){
            int mid = ss + (se - ss)/2;
            updateUtil(ss, mid, index, diff, 2 * si + 1);
            updateUtil(mid + 1, se, index, diff, 2 * si + 2);
        }
    }
    
    void update(int index, int val) {
        if(index < 0 || index > arr.size() -1) return;
        int diff = val - arr[index];
        arr[index] = val;
        updateUtil(0, arr.size()-1, index, diff, 0);
    }
    
    int sumRangeUtil(int ss, int se, int left, int right, int si){
        if(left <= ss && right >= se) return st[si];
        if(left > se || right < ss) return 0;
        int mid = ss + (se - ss)/2;
        return sumRangeUtil(ss, mid, left, right, 2*si + 1) + 
            sumRangeUtil(mid + 1, se, left, right, 2*si + 2);
    }
    
    int sumRange(int left, int right) {
        if(left < 0 || right > arr.size() - 1) return -1;
        return sumRangeUtil(0, arr.size() - 1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
