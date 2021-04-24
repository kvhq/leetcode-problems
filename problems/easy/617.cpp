// Number: 617
// Name: Merge Two Binary Trees
// Tags: bst, stack, recursion

// queue
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1) return root2;
    queue<TreeNode*> q_1;
    queue<TreeNode*> q_2;
    q_1.push(root1);
    q_2.push(root2);
    while(!q_1.empty() && !q_2.empty()) {
        TreeNode* c_1 = q_1.front();
        q_1.pop();
        TreeNode* c_2 = q_2.front();
        q_2.pop();
        if (c_1 && c_2) {
            c_1->val += c_2->val;
            if (!c_1->left && c_2->left) c_1->left = c_2->left;
            else {
                q_1.push(c_1->left);
                q_2.push(c_2->left);
            }
            if (!c_1->right && c_2->right) c_1->right = c_2->right;
            else {
                q_1.push(c_1->right);
                q_2.push(c_2->right);
            }
        }
    }
    return root1;
}

// recursion
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr) return t2;
    if (t2 == nullptr) return t1;
    t1->val = t1->val + t2->val;
    if (t1->right && t2->right) {
        t1->right = mergeTrees(t1->right, t2->right);
    }
    if (!t1->right && t2->right) {
        t1->right = t2->right;
    }
    if (t1->left && t2->left) {
        t1->left = mergeTrees(t1->left, t2->left);
    }
    if (!t1->left && t2->left) {
        t1->left = t2->left;
    }
    return t1;
}

// stack
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

