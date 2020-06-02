// Number: 237
// Name: Delete Node in a Linked List
// Tags: linked list, pointers

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

