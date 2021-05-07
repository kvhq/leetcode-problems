// Number: 199
// Name: Binary Tree Right Side View
// Tags: Tree, BFS

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer = {};
        if (!root) return answer;
        queue<TreeNode*> data;
        data.push(root);
        int counter = 1;
        while(!data.empty()) {
            answer.push_back(data.back()->val);
            int prev_level = counter;
            counter = 0;
            while(prev_level != 0) {
                TreeNode* cur = data.front();
                data.pop();
                prev_level--;
                if (cur->left) {
                    data.push(cur->left);
                    counter++;
                }
                if (cur->right) {
                    data.push(cur->right);
                    counter++;
                }
            }
        }
        return answer;
    }
};

