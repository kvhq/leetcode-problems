// Number: 21
// Name: Merge Two Sorted Lists
// Tags: Linked list

// iterative
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

// recursion
class Solution {
public:
    void mergeNodes(ListNode* prevNode, ListNode* n1, ListNode* n2) {
        if (!n1 && !n2) return;
        if (!n1) prevNode->next = n2;
        else if (!n2) prevNode->next = n1;
        else {
            if (n1->val <= n2->val) {
                prevNode->next = n1;
                mergeNodes(n1, n1->next, n2);
            } else {
                prevNode->next = n2;
                mergeNodes(n2, n1, n2->next);
            }
        }
        return;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return l1;
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val <= l2->val) {
            mergeNodes(l1, l1->next, l2);
            return l1;
        }
        mergeNodes(l2, l2->next, l1);
        return l2;
    }
};

