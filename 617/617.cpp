TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t2) return t1;
    if (!t1) return t2;
    stack<pair<TreeNode*, TreeNode*>> myS;
    pair<TreeNode*, TreeNode*> temp = make_pair(t1, t2);
    myS.push(temp);
    while (myS.size() != 0) {
        temp = myS.top();
        myS.pop();
        if (!temp.first) {
            temp.first = temp.second;
            continue;
        }
        else if (!temp.second) continue;
        
        temp.first->val += temp.second->val;
        
        if (!temp.first->left) {
            temp.first->left = temp.second->left;
        }
        else if (temp.second->left) {
            pair<TreeNode*, TreeNode*> newTemp = make_pair(temp.first->left, temp.second->left);
            myS.push(newTemp);
        }
        if (!temp.first->right) {
            temp.first->right = temp.second->right;
        }
        else if (temp.second->right) {
            pair<TreeNode*, TreeNode*> newTemp = make_pair(temp.first->right, temp.second->right);
            myS.push(newTemp);
        }
    }
    return t1;
}