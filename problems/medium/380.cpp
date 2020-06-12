// Number: 380
// Name: Insert Delete GetRandom O(1)
// Tags: structure design

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (data_to_pos.find(val) != data_to_pos.end()) return false;
        data.emplace_back(val);
        data_to_pos[val] = data.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (data_to_pos.find(val) == data_to_pos.end()) return false;
        int last = data.back();
        data_to_pos[last] = data_to_pos[val];
        data[data_to_pos[val]] = last;
        data.pop_back();
        data_to_pos.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }
private:
    unordered_map<int, int> data_to_pos;
    vector<int> data;
};

