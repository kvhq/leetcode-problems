//Number: 543
//Name: Diameter of Binary Tree
//Tags: tree

class Solution {
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

