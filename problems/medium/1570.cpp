// number: 1570
// name: Dot Product of Two Sparse Vectors
// tags: two pointers, hash map

class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != 0) {
                indexes.push_back(i);
                data.push_back(nums[i]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i = 0;
        int j = 0;
        int ans = 0;
        while (i < (int)indexes.size() && j < (int)vec.indexes.size()) {
            if (indexes[i] == vec.indexes[j]) {
                ans += data[i]*vec.data[j];
                i++;
                j++;
            } else if (indexes[i] < vec.indexes[j]) i++;
            else j++;
        }
        return ans;
    }

    vector<int> indexes;
    vector<int> data;
};

