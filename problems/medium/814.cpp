// Number: 814
// Name: Binary Tree Pruning
// Tags: binary tree, recursion

TreeNode* pruneTree(TreeNode* root) {
    if (root == nullptr) return root;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 0 && root->left == nullptr && root->right == nullptr) root = nullptr;
    return root;
}

