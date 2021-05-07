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

// clearer a bit
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.empty()) return;
        int back_p = n + m - 1;
        int p_1 = m - 1;
        int p_2 = n - 1;
        while (back_p > -1 && p_2 > -1 && p_1 > -1) {
            if (nums1[p_1] >= nums2[p_2]) {
                nums1[back_p] = nums1[p_1];
                p_1--;
            } else {
                nums1[back_p] = nums2[p_2];
                p_2--;
            }
            back_p--;
        }
        if (p_1 == -1) {
            while (p_2 > -1) {
                nums1[back_p] = nums2[p_2];
                back_p--;
                p_2--;
            }
        }
        return;
    }
};

