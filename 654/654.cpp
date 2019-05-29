struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* getHead(int startIndex, int endIndex, vector<int>& nums) {
    if (startIndex > endIndex) {
        return NULL;
    }
    int tempValue = 0;
    int maxIndex = 0;
    for (int i = startIndex; i <= endIndex; ++i) {
        if (nums[i] >= tempValue) {
            tempValue = nums[i];
            maxIndex = i;
        }
    }
    TreeNode* head = new TreeNode(tempValue);
    head->left = getHead(startIndex, maxIndex - 1, nums);
    head->right = getHead(maxIndex + 1, endIndex, nums);
    return head;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int startIndex = 0;
    int endIndex = nums.size() - 1;
    TreeNode* head = getHead(startIndex, endIndex, nums);
    return head;
}