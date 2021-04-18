// Number: 101
// Name: Symmetric Tree
// Tags: tree, recursion

// Check level by level
// Time complexity O(n)

class Solution_1 {
public:
    bool checkLevel(const vector<TreeNode*>& level) {
        if ((int)level.size() % 2 != 0) return false;
        int low = 0;
        int top = (int)level.size() - 1;
        while (low < top) {
            if (!level[low] && level[top]) return false;
            if (!level[top] && level[low]) return false;
            if (!level[top] && !level[low]) {
                low++;
                top--;
            } else if (level[low]->val != level[top]->val) return false;
            else {
                low++;
                top--;
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root->left && !root->right) return true;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            vector<TreeNode*> level;
            while (!q.empty()) {
                level.push_back(q.front());
                q.pop();
            }
            if (!checkLevel(level)) return false;
            for (const auto& x : level) {
                if (x) {
                    q.push(x->left);
                    q.push(x->right);
                }
            }
        }
        return true;
    }
};

// Recursion

class Solution_2 {
public:
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2) return true;
        if (!n1 || !n2) return false;
        return n1->val == n2->val && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};

