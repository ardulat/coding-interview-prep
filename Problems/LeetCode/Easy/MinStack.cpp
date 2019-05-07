// https://leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<int> s, mins;
    int minimum;
public:
    /** initialize your data structure here. */
    MinStack() {
        s = stack<int>();
        mins = stack<int>();
        minimum = INT_MAX;
    }
    
    void push(int x) {
        s.push(x);
        if (x < minimum)
            minimum = x;
        mins.push(minimum);
    }
    
    void pop() {
        s.pop();
        mins.pop();
        if (!mins.empty())
            minimum = mins.top();
        else
            minimum = INT_MAX;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */