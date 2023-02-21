class MyCalendar {
public:
    map<int, int> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        map<int, int>::iterator it = cal.upper_bound(start);
        if(it == cal.end() || (*it).second >= end){
            cal.insert({end, start});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
