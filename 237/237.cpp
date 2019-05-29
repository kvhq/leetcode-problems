void deleteNode(ListNode* node) {
    node->val = node->next->val;
    if (node->next->next == NULL) {
        node->next = NULL;
        return;
    }
    else {
        deleteNode(node->next);
    }
    return;
}