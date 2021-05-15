// Number: 94
// Name: Binary Tree Inorder Traversal
// Tags: tree

// iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            answer.push_back(root->val);
            root = root->right;
        }
        return answer;
    }
};


