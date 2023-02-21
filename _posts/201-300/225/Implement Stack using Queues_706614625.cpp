class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
         
    }
    
    void push(int x) {
        int n = q1.size();
        q1.push(x);
        while(n--){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();    
    }
    
    bool empty() {
        return q1.empty();
    }
};
