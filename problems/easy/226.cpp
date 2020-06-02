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

