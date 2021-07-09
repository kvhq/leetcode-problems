// Number: 341
// Name: Flatten Nested List Iterator
// Tags: design, stack

// constructor: O(N+M) , other method: O(1);
// space: O(N)
class NestedIterator_0 {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        deque<NestedInteger> d_deque;
	for (const auto& x : nestedList)
            d_deque.push_back(x);
        while (!d_deque.empty()) {
            NestedInteger curObj = d_deque.front();
            d_deque.pop_front();
            while (!curObj.isInteger() || d_deque.empty()) {
                auto curList = curObj.getList();
                if (curList.empty()) break;
                for (auto it = curList.rbegin(); it != curList.rend(); ++it)
                    d_deque.push_front(*it);
                curObj = d_deque.front();
                d_deque.pop_front();
            }
            if (curObj.isInteger()) d_data.push(curObj.getInteger());
        }
    }
    
    int next() {
        NestedInteger curObj = d_data.front();
        d_data.pop();
        return curObj.getInteger();
    }
    
    bool hasNext() {
        if (d_data.empty()) return false;
        return true;
    }
private:
    queue<int> d_data;
};



