class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(small.empty() || small.top() > num) small.push(num);
        else big.push(num);
        
        if(small.size() > big.size() + 1L){
            big.push(small.top());
            small.pop();
        }
        
        else if (small.size() < big.size()){
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if(small.size() == big.size()) return (small.top() + big.top())/2.0;
        else if(small.size() > big.size()) return small.top();
        else return big.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
