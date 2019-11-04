class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!s2.empty()) {
            int x = s2.top();
            s2.pop();
            return x;
        }
        while (!s1.empty()) {
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        while (!s1.empty()) {
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (s1.empty() && s2.empty()) {
            return true;
        }
        return false;
    }
    
    stack<int> s1;
    stack<int> s2;
};


