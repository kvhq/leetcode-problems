// Number: 1428
// Name: Leftmost Column with at Least a One
// Tags: array, binary search

// O (N + M)
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int rows = dims[0];
        int cols = dims[1];
        int cur_row = 0;
        int candidate = -1;
        for (int i = cols - 1; i >= 0;) {
            if (binaryMatrix.get(cur_row, i) == 1) {
                if (i == 0) return 0;
                candidate = i;
                i--;
            } else {
                if (cur_row == rows - 1) return candidate;
                cur_row++;
            }
        }
        return candidate;
    }
};

// Binary search solution goes here
class Solution_1 {
public:
    int binarySearch(BinaryMatrix& binaryMatrix, int rhs, int cols, int cur_row) {
        int lhs = 0;
        if (rhs < 0) rhs = cols - 1;
        while (lhs < rhs) {
            int middle = lhs + (rhs - lhs) / 2;
            if (binaryMatrix.get(cur_row, middle) == 0) {
                if (middle == cols - 1) return -1;
                lhs = middle + 1;
            } else {
                if (middle == 0) return 0;
                rhs = middle;
            }
        }
        if (binaryMatrix.get(cur_row, lhs) == 1) {
            return lhs;
        }
        return -1;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int rows = dims[0];
        int cols = dims[1];
        int cur_row = 0;
        int candidate = -1;
        while (cur_row < rows) {
            int cur_candidate = binarySearch(binaryMatrix, candidate - 1, cols, cur_row);
            if (cur_candidate != -1) {
                candidate = candidate == -1 ? cur_candidate : min(cur_candidate, candidate);
            }
            if (cur_candidate == 0) return 0;
            cur_row++;
        }
        return candidate;
    }
};

