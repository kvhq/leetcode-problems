class MinStack {
private:
    std::stack<int> minS;
    std::stack<int> defS;
public:
    void push(x) {
        defS.push(x);
        if (minS.empty() || x <= getMin()) {
            minS.push(x);
        }
    }

    void pop() {
        if (defS.top() == getMin()) {
            minS.pop();
        }
        defS.pop();
    }

    int top() {
        return defS.top();
    }

    int getMin() {
        return minS.top();
    }
};
