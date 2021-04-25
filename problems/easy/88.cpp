//Number: 88
//Name: Merge Sorted Array
//Tags: array, pointers

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int start = nums1.size() - 1;
        int n2_start = nums2.size() - 1;
        int n1_start = m - 1;
        for (int i = start; i > -1; --i) {
            if (n2_start < 0) return;
            if (n1_start < 0) {
                for (int j = i; j > -1; --j) {
                    nums1[j] = nums2[n2_start];
                    n2_start--;
                }
                return;
            }
            if (nums2[n2_start] >= nums1[n1_start]) {
                nums1[i] = nums2[n2_start];
                n2_start--;
            } else {
                nums1[i] = nums1[n1_start];
                n1_start--;
            }
        }
    }
};

