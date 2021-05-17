// Number: 863
// Name: All Nodes Distance K in Binary Tree
// Tags: tree, BFS, DFS

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> answer;
        unordered_map<TreeNode*, bool> visited;
        unordered_map<TreeNode*, TreeNode*> parents;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curTop = q.front(); q.pop();
            if (curTop->left) {
                parents[curTop->left] = curTop;
                q.push(curTop->left);
            }
            if (curTop->right) {
                parents[curTop->right] = curTop;
                q.push(curTop->right);
            }
        }
        int curDistance = 0;
        q.push(target);
        visited[target] = true;
        while (!q.empty()) {
            int toTraverse = q.size();
            if (curDistance++ == k) break;
            for (int i = 0; i < toTraverse; ++i) {
                TreeNode* curNode = q.front(); q.pop();
                if (curNode->left && !visited[curNode->left]) {
                    q.push(curNode->left);
                    visited[curNode->left] = true;
                }
                if (curNode->right && !visited[curNode->right]) {
                    q.push(curNode->right);
                    visited[curNode->right] = true;
                }
                if (parents[curNode] && !visited[parents[curNode]]) {
                    q.push(parents[curNode]);
                    visited[parents[curNode]] = true;
                }
            }
        }
        while (!q.empty()) {
            TreeNode* curNode = q.front(); q.pop();
            answer.push_back(curNode->val);
        }
        return answer;
    }
};

