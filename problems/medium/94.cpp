// Number: 94
// Name: Binary Tree Inorder Traversal
// Tags: tree

class Solution_0 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> answer;
        stack<TreeNode*> st;
        while (!st.empty() || root) {
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

// recursive solution
class Solution_1 {
public:
    void helper(TreeNode* n, vector<int>& answer) {
        if (!n) return;
        helper(n->left, answer);
        answer.push_back(n->val);
        helper(n->right, answer);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        helper(root, answer);
        return answer;
    }
};

