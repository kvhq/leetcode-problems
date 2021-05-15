// Number: 1038
// Name: Binary Search Tree to Greater Sum Tree
// Tags: BST, traverse

// recursive
class Solution {
public:
    int helper(TreeNode* node, int upValue) {
        if (!node) return upValue;
        node->val += helper(node->right, upValue);
        return helper(node->left, node->val);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        helper(root, 0);
        return root;
    }
};

// iterative
class Solution_1 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        stack<TreeNode*> st;
        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->right;
            }
            node = st.top();
            st.pop();
            sum += node->val;
            node->val = sum;
            node = node->left;
        }
        return root;
    }
};

