class MyCalendar {
public:
    map<int, int> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = cal.upper_bound(start);
        if(it == cal.end()){
            cal.insert({end, start});
            return true;
        }
        if((*it).second < end) return false;
        cal.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
