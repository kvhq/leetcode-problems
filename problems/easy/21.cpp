// Number: 21
// Name: Merge Two Sorted Lists
// Tags: Linked list

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* headNode = nullptr;
    if (l1->val < l2->val) {
        headNode = l1;
        l1 = l1->next;
    } else {
        headNode = l2;
        l2 = l2->next;
    }
    ListNode* curNode = headNode;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            curNode->next = l1;
            l1 = l1->next;
        } else {
            curNode->next = l2;
            l2 = l2->next;
        }
        curNode = curNode->next;
    }

    if (l1) curNode->next = l1;
    else curNode->next = l2;

    return headNode;
}

