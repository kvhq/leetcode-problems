
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helpFunc(TreeNode* root, int& sum) {
    if (root == NULL) {
        return;
    }
    helpFunc(root, sum);
    int temp = sum;
    sum += root->val;
    root->val = temp;
    helpFunc(root, sum);
}

TreeNode* bstToGst(TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    int sum = 0;
    helpFunc(root, sum);
    return root;
}