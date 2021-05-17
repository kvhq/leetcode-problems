// Number: 144
// Name: Binary Tree Preorder Traversal
// Tags: tree, stack

// iterative solution
class Solution_0 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer = {};
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur) {
                answer.push_back(cur->val);
                st.push(cur->right);
                st.push(cur->left);
            }
        }
        return answer;
    }
};

// recursive
class Solution_1 {
public:
    void helper(TreeNode* n, vector<int>& answer) {
        if (!n) return;
        answer.push_back(n->val);
        helper(n->left, answer);
        helper(n->right, answer);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer = {};
        helper(root, answer);
        return answer;
    }
};

