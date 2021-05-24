// Number: 136
// Name: Single Number
// Tags: Math, Bit Manipulation

int singleNumber(vector<int>& nums) {
    map<int,int> freqMap;
    for (const auto& x : nums) {
        freqMap[x]++;
    }
    for (const auto& x : freqMap) {
        if (x.second == 1) {
            return x.first;
        }
    }
    return 0;
}

//should be done one more solution
//using bit manipulation
