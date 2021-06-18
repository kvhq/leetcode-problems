// Number: 333
// Name: Largest BST Subtree
// Tags: Tree

// time O(n*log(n)) space O(logN)
class Solution_0 {
public:
    bool isBST(TreeNode* root, int& nodeCounter) {
        if (!root) return false;
        stack<TreeNode*> st;
        TreeNode* prevNode = nullptr;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            nodeCounter++;
            if (!prevNode || prevNode->val < root->val) prevNode = root;
            else return false;
            st.pop();
            root = root->right;
        }
        return true;
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        int answer = 0;
        int curNodeCounter = 0;
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
            if (isBST(root, curNodeCounter)) answer = max(answer, curNodeCounter);
            curNodeCounter = 0;
            q.pop();
        }
        return answer;
    }
};

// 

