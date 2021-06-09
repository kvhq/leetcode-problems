// Number: 941
// Name: Valid Mountain Array
// Tags: array

// one pass with flag
class Solution_1 {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int state = 0; // 0 - init ; 1 - up ; 2 - down
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == arr[i - 1]) return false;
            if (arr[i] < arr[i - 1]) {
                if (state == 0) return false;
                if (state == 1) state = 2;
            }
            if (arr[i] > arr[i - 1]) {
                if (state == 2) return false;
                if (state == 0) state = 1;
            }
        }
        if (state != 2) return false;
        return true;
    }
};

// clime from both sides O(N)class Solution_2 {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int lhs = 0;
        int rhs = arr.size() - 1;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[lhs]) lhs++;
            else break;
        }
        for (int i = arr.size() - 2; i >= 0; --i) {
            if (arr[i] > arr[rhs]) rhs--;
            else break;
        }
        return lhs == rhs && lhs != 0 && rhs != arr.size() - 1;
    }
};


