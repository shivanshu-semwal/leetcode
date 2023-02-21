class PeekingIterator : public Iterator {
public:
    int val1, val2;
    bool hNext1, hNext2;
    
    void ff(){
        if(Iterator::hasNext()){         
            hNext1 = true;
            val1 = Iterator::next();
            
            if(Iterator::hasNext()){
                hNext2 = true;
                val2 = Iterator::next();
            } else {
                hNext2 = false;
                val2 = 0;
            }
            
        } else{
            hNext1 = false;
            hNext2 = false;
            val1 = 0;
            val2 = 0;
        }
        cout << val1 << val2 << endl;
    }
    
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        ff();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        // cout << val1 << val2 << endl;
        return val1;
    }

    int next() {
        // cout << val1 << val2 << endl;
        int temp = val1;
        
        if(Iterator::hasNext()){   
            hNext1 = hNext2;
            hNext2 = true;
            val1 = val2;
            val2 = Iterator::next();
        } else{
            hNext1 = hNext2;
            hNext2 = false;
            val1 = val2;
            val2 = 0;
        }
        
        return temp;
    }
    
    bool hasNext() const {
        // cout << val1 << val2 << endl;
        return hNext1;
    }
};
