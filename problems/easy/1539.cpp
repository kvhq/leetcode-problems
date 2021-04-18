// Number: 1539
// Name: Kth Missing Positive Number
// Tags: array

// Bruteforce O(N)

class Solution_1 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int all_n = 1;
        int arr_index = 0;
        while (arr_index < (int)arr.size()) {
            if (arr[arr_index] == all_n) {
                arr_index++;
                all_n++;
            } else {
                int diff = arr[arr_index] - all_n;
                if (k - diff  > 0) { 
                    k -= diff;
                    all_n += diff;
                }
                else {
                    return all_n + k - 1;
                }
            }
        }
        return all_n + k - 1;
    }
};

// Binary Searth O(logN)

class Solution_2 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = (int)arr.size() - 1;
        
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            if (arr[pivot] - pivot - 1 < k) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        return left + k;
    }
};

