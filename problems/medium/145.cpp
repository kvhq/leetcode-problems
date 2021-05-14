// Number: 145
// Name: Binary Tree Postorder Traversal
// Tags: tree, stack, Morris

// recursive O(N), O(N)
class Solution_0 {
public:
    void helper(TreeNode* n, vector<int>& ans) {
        if (!n) return;
        helper(n->left, ans);
        helper(n->right, ans);
        ans.push_back(n->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> answer;
        helper(root, answer);
        return answer;
    }
};

// iterative O(N), O(N)


