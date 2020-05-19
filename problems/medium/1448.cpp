// Number: 1448
// Name: Count Good Nodes in Binary Tree
// Tags: binary tree, traversal

int findGoodNodes(TreeNode* node, int curMax) {
    if (!node) return 0;
    int answer = 0;
    if (node->val >= curMax) {
        answer++;
        curMax = node->val;
    }
    return answer + findGoodNodes(node->left, curMax) + findGoodNodes(node->right, curMax);
}

int goodNodes(TreeNode* root) {
    return findGoodNodes(root, -10000);
}

