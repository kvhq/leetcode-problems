// Number: 572
// Name: Subtree of Another Tree
// Tags: tree, DFS, BFS

// O(N*M) no recursion
class Solution_0 {
public:
    bool checkCandidate(TreeNode* candidate, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(candidate);
        queue<TreeNode*> subQ;
        subQ.push(subRoot);
        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            if (subQ.empty()) return false;
            TreeNode* subCurNode = subQ.front();
            subQ.pop();
            if (!curNode && !subCurNode) continue;
            if (!curNode) return false;
            if (!subCurNode) return false;
            if (curNode->val != subCurNode->val) return false;
            if (curNode) {
                q.push(curNode->left);
                q.push(curNode->right);
                subQ.push(subCurNode->left);
                subQ.push(subCurNode->right);
            }
        }
        return true;
    }
    
    vector<TreeNode*> getRoots(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> roots;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            if (curNode->val == subRoot->val) roots.push_back(curNode);
            if (curNode->left) q.push(curNode->left);
            if (curNode->right) q.push(curNode->right);
        }
        return roots;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        vector<TreeNode*> roots = getRoots(root, subRoot);
        for (const auto& x : roots) {
            if (checkCandidate(x, subRoot)) return true;
        }
        return false;
    }
};

// O(N + M) no recursion
class Solution {
public:
    string getPreOrder(TreeNode* root) {
        string res = "|";
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            if (root) {
                res += to_string(root->val);
                res += '|';
                st.push(root->right);
                st.push(root->left);
            } else res += '#|';
        }
        return res;
    }
    
    string getInOrder(TreeNode* root) {
        string res = "|";
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res += to_string(root->val);
            res += '|';
            root = root->right;
        }
        return res;
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootLevelStr = getPreOrder(root);
        string subLevelStr = getPreOrder(subRoot);
        string rootInOrderStr = getInOrder(root);
        string subInOrderStr = getInOrder(subRoot);
        if (rootLevelStr.find(subLevelStr) != string::npos &&
            rootInOrderStr.find(subInOrderStr) != string::npos) return true;
        return false;
    }
};

