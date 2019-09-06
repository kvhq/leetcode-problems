int repeatedNTimes(vector<int>& A) {
    unordered_map<int, int> counters;
    for(const auto& x : A) {
        counters[x]++;
        if(counters[x] > 1) {
            return x;
        }
    }
    return A[0];
}