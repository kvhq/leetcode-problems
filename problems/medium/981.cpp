// Number: 981
// Name: Time Based Key-Value Store
// Tags: hashmap, binary search

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    int binSearch(const vector<int>& c_t, int t) {
        int lhs = 0;
        int rhs = c_t.size() - 1;
        int mid = 0;
        while (lhs < rhs) {
            if ((rhs - lhs) % 2 == 0) mid = lhs + (rhs - lhs) / 2;
            else mid = lhs + (rhs - lhs) / 2 + 1;
            if (c_t[mid] == t) return t;
            else if (c_t[mid] < t) lhs = mid;
            else rhs = mid - 1;
        }
        return c_t[lhs];
    }
    
    void set(string key, string value, int timestamp) {
        if (d_times.find(key) == d_times.end()) {
            d_times[key] = {timestamp};
        } else d_times[key].push_back(timestamp);
        d_data[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        const vector<int>& c_times = d_times[key];
        if (c_times.empty()) return "";
        int t = binSearch(c_times, timestamp);
        if (t > timestamp) return "";
        return d_data[t];
    }
private:
    unordered_map<string, vector<int>> d_times;
    unordered_map<int, string> d_data;
};

