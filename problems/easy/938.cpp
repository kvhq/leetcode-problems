//Number: 938
//Name: Range Sum of BST
//Tags: binary search tree, recursion

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void countSum(TreeNode* root, int L, int R, int& sum) {
    if (!root) {
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
    if (!root) {
        return 0;
    }
    countSum(root, L, R, answer);
    return answer;
}
