// Number: 53
// Name: Maximum Subarray
// Tags: array, two pointer, dp

int maxSubArray(vector<int>& v) {
    size_t lo;
    int max_sum, max_neg, cur_sum;
    cur_sum = 0;
    max_sum = -1;
    max_neg = 0;
    lo = -1;
    for (size_t i = 0; i < v.size(); ++i) {
        if (lo == -1) {
            if (v[i] >= 0) {
                lo = i;
                cur_sum = v[i];
                if (cur_sum > max_sum) max_sum = cur_sum;
            } else if (max_neg == 0 || max_neg < v[i]) max_neg = v[i];
        } else {
            cur_sum += v[i];
            if (cur_sum <= 0) lo = -1;
            else if (cur_sum > max_sum) max_sum = cur_sum;
        }
    }
    if (max_sum < 0) return max_neg;
    return max_sum;
}
