class CountIntervals {
public:
    map<int, int> r2l;
    int c;
    
    CountIntervals() {
         r2l = map<int, int>();
         c = 0;
    }
    
    void add(int left, int right) {
        int s = left, e = right;
        auto it = r2l.lower_bound(left);
        while (it != r2l.end() && it->second <= right) {
            s = min(s, it->second);
            e = max(e, it->first);            
            c = c - (it->first - it->second + 1);
            it = r2l.erase(it);
        }
        r2l[e] = s;
        c += e-s + 1;
    }
    
    int count() {
        return c;
    }
};
