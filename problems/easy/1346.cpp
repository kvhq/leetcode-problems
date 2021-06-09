// Number: 1346
// Name: Check If N and Its Double Exist
// Tags: array

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> data;
        for (int i = 0; i < arr.size(); ++i) 
            data[arr[i]] = i;
        for (int i = 0; i < arr.size(); ++i)
            if (data.find(arr[i] * 2) != data.end() && data[arr[i] * 2] != i) return true;
        return false;
    }
};

