// Number: 173
// Name: Binary Search Tree Iterator
// Tags: stack, tree traversal

// O(N) space
class BSTIterator_0 {
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            d_data.push_back(root->val);
            root = root->right;
        }
        cur_node_index = 0;
    }
    
    int next() {
        return d_data[cur_node_index++];
    }
    
    bool hasNext() {
        if (cur_node_index == d_data.size()) return false;
        return true;
    }
private:
    int cur_node_index;
    vector<int> d_data;
};

// O(logN) space
class BSTIterator_1 {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            d_data.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* cur = d_data.top();
        d_data.pop();
        TreeNode* upcomingNode = cur->right;
        while (upcomingNode) {
            d_data.push(upcomingNode);
            upcomingNode = upcomingNode->left;
        }
        return cur->val;
    }
    
    bool hasNext() {
        return (!d_data.empty());
    }
private:
    stack<TreeNode*> d_data;
};

