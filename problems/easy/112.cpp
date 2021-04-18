// Number: 112
// Name: Path Sum
// Tags: tree

class Solution_1 {
public:
    bool helper(TreeNode* n, int sum, int target) {
        if (!n) return false;
        sum += n->val;
        if (!n->left && !n->right && sum == target) return true;
        return helper(n->left, sum, target) || helper(n->right, sum, target);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return helper(root, 0, targetSum);
    }
};

