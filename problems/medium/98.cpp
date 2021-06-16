// Number: 98
// Name: Validate Binary Search Tree
// Tags: Tree

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root->left && !root->right) return true;
        stack<TreeNode*> st;
        TreeNode* preNode = nullptr;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if (!preNode) preNode = root;
            else {
                if (root->val <= preNode->val) return false;
                preNode = root;
            }
            st.pop();
            root = root->right;
        }
        return true;
    }
};

