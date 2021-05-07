// Number: 270
// Name: Closest Binary Search Tree Value
// Tags: binary tree

// binary tree search recursive O(H) time and O(H) space
class Solution_1 {
public:
    int findClosetValue(TreeNode* n, double target, int& candidate) {
        if (!n) return candidate;
        if (abs(n->val - target) <= 0.5) return n->val;
        if (abs(n->val - target) < abs(candidate - target)) candidate = n->val;
        if (n->val < target) return findClosetValue(n->right, target, candidate);
        return findClosetValue(n->left, target, candidate);
    }
    
    int closestValue(TreeNode* root, double target) {
        int candidate = root->val;
        return findClosetValue(root, target, candidate);
    }
};

// binary search without recursion O(H) time and O(1) space
class Solution_2 {
public:
    int closestValue(TreeNode* root, double target) {
        int candidate = root->val;
        while (root) {
            if (abs(root->val - target) <= 0.5) return root->val;
            if (abs(root->val - target) < abs(candidate - target)) candidate = root->val;
            if (root->val < target) root = root->right;
            else root = root->left;
        }
        return candidate;
    }
};

