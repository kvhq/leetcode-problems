// Number: 933
// Name: Number of Recent Calls
// Tags: design, queue

class RecentCounter {
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        while (pings.size() != 0 && t - pings.front() > 3000) {
            pings.pop();
        }
        pings.push(t);
        return pings.size();
    }
    
    queue<int> pings;
};

