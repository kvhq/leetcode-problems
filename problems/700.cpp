// using recursion
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        return root;
    }
    if (val > root->val) {
        if (root->right == NULL) {
            return NULL;
        }
        return searchBST(root->right, val);
    }
    if (val < root->val) {
        if (root->left == NULL) {
            return NULL;
        }
        return searchBST(root->left, val);
    }
    return NULL;
}

// iterative solution
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    while (root) {
        if (root->val == val) {
            return root;
        }
        if (root->left != NULL && val < root->val) {
            root = root->left;
        } else if (root->right != NULL && val > root->val) {
            root = root->right;
        } else {
            return NULL;
        }
    }
    return NULL;
}
