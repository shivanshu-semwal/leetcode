class MinStack {
public:
    vector<int> min_vector;
    int min_pointer;
    int min_size;

    vector<int> arr;
    int pointer;
    int size;

    MinStack() {
        min_vector.reserve(1000);
        arr.reserve(1000);
        size = 0;
        min_size = 0;
        pointer = -1;
        min_pointer = -1;
    }

    void push(int val) {

        if (min_pointer == -1 || val <= min_vector[min_pointer]) {
            min_pointer++;
            if (min_pointer == min_size) {
                min_vector.push_back(val);
                min_size++;
            } else {
                min_vector[min_pointer] = val;
            }
        }

        pointer++;
        if (pointer == size) {
            arr.push_back(val);
            size++;
        } else {
            arr[pointer] = val;
        }
    }

    void pop() {
        if (arr[pointer] == min_vector[min_pointer]) min_pointer--;
        pointer--;
    }

    int top() {
        return arr[pointer];
    }

    int getMin() {
        return min_vector[min_pointer];
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
