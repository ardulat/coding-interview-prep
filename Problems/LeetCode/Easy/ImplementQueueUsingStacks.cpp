// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
private:
    stack<int> q, rev;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int front = -1;
        
        while (!q.empty()) {
            front = q.top();
            q.pop();
            rev.push(front);
        }
        
        rev.pop(); // last element
        
        while (!rev.empty()) {
            q.push(rev.top());
            rev.pop();
        }
        
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        int front = -1;
        
        while (!q.empty()) {
            front = q.top();
            q.pop();
            rev.push(front);
        }
        
        while (!rev.empty()) {
            q.push(rev.top());
            rev.pop();
        }
        
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */