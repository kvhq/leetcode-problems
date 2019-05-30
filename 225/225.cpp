class MyStack {
private:
    queue<int> myQ;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myQ.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tempQ;
        int myQSize = myQ.size();
        for (int i = 0; i < myQSize - 1; ++i) {
            tempQ.push(myQ.front());
            myQ.pop();
        }
        myQSize = myQ.front();
        myQ = tempQ;
        return myQSize;
    }
    
    /** Get the top element. */
    int top() {
        queue<int> tempQ;
        int myQSize = myQ.size();
        for (int i = 0; i < myQSize - 1; ++i) {
            tempQ.push(myQ.front());
            myQ.pop();
        }
        myQSize = myQ.front();
        tempQ.push(myQSize);
        myQ = tempQ;
        return myQSize;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myQ.empty();
    }
};
