//Number: 113
//Name: Path Sum II
//Tags: DFS

class Solution {
public:
    void getPaths(TreeNode* node, int curSum, int target, vector<int>& path, vector<vector<int>>& answer) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (curSum + node->val == target) answer.push_back(path);
        }
        getPaths(node->left, curSum + node->val, target, path, answer);
        getPaths(node->right, curSum + node->val, target, path, answer);
        path.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> answer;
        vector<int> path;
        getPaths(root, 0, targetSum, path, answer);
        return answer;
    }
};

