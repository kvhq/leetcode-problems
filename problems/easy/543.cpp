//Number: 543
//Name: Diameter of Binary Tree
//Tags: tree

// recursive version 0
class Solution_0 {
public:
    int helper(TreeNode* n, int& answer) {
        if (!n) return -1;
        if (!n->left && !n->right) return 0;
        int left = 1 + helper(n->left, answer);
        int right = 1 + helper(n->right, answer);
        answer = max(answer, left + right);
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int answer = 0;
        return max(helper(root, answer), answer);
    }
};

// recursive version 1
class Solution_1 {
public:
    int helper(TreeNode* node, int& d) {
        if (!node) return 0;
        int lhs = helper(node->left, d);
        int rhs = helper(node->right, d);
        if (lhs + rhs > d) d = lhs + rhs;
        return 1 + max(lhs, rhs);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root->right, diameter);
        return diameter;
    }
};

// iterative solution

