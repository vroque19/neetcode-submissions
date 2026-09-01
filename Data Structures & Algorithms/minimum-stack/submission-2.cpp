class MinStack {
    int min;
    stack<tuple<int, int>> min_stack; // hold the curr val and curr min
public:
    MinStack() {
       min_stack = {};
       min = 0;

    }
    
    void push(int val) {
        if(min_stack.empty()) {
            min = val;
        }
        if(val < min) {
            min = val;
        }
        min_stack.push(make_pair(val, min));
    }
    
    void pop() {
        min_stack.pop();
        if(min_stack.empty()) {
            return;
        }
        min = get<1>(min_stack.top());
    }
    
    int top() {
        int val = 0;
        val = get<0>(min_stack.top());
        return val;
    }
    
    int getMin() {
        
        return min;
        
    }
};
