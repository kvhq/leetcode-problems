struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void countSum(TreeNode* root, int L, int R, int& sum) {
    if (root == NULL) {
        return;
    }
    if (root->val >= L && root->val <= R) {
        sum += root->val;
    }
    countSum(root->left, L, R, sum);
    countSum(root->right, L, R, sum);
}
    
int rangeSumBST(TreeNode* root, int L, int R) {
    int answer = 0;
    if (root == NULL) {
        return 0;
    }
    countSum(root, L, R, answer);
    return answer;
}