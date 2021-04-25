// Number: 226
// Name: Invert Binary Tree
// Tags: tree

TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
}

// recursive

class Solution {
public:
    void invertChildren(TreeNode* node) {
        if (!node) return;
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        invertChildren(node->left);
        invertChildren(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        invertChildren(root);
        return root;
    }
};

