// Number: 1448
// Name: Count Good Nodes in Binary Tree
// Tags: binary tree, traversal

// old one
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

//
class Solution {
public:
    void findGoodNodes(TreeNode* n, int cur_max, int& totalGood) {
        if (!n) return;
        if (n->val >= cur_max) {
            totalGood++;
            cur_max = n->val;
        }
        findGoodNodes(n->left, cur_max, totalGood);
        findGoodNodes(n->right, cur_max, totalGood);
    }
    
    int goodNodes(TreeNode* root) {
        int answer = 0;
        int cur_max = root->val;
        findGoodNodes(root, cur_max, answer);
        return answer;
    }
};

