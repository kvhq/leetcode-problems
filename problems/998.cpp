TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (!root || root->val < val) {
        TreeNode* nRoot = new TreeNode(val);
        nRoot->left = root;
        return nRoot;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
}