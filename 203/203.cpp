ListNode* helpFunc(ListNode* head, ListNode* pN,
                ListNode* cN, ListNode* nN, int val) {
    if (head->val == val) {
        head = nN;
        cN = nN;
        if (!nN) {
            return head;
        }
        nN = nN->next;
        return helpFunc(head, pN, cN, nN, val);
    }
    else {
        if (cN->val != val) {
            if (!nN) {
                return head;
            }
            pN = cN;
            cN = nN;
            nN = nN->next;
            return helpFunc(head, pN, cN, nN, val);
        }
        else if (cN->val == val) {
            pN->next = nN;
            cN = nN;
            if (!nN) {
                return head;
            }
            nN = nN->next;
            return helpFunc(head, pN, cN, nN, val);
        }
    }
    return head;
}

ListNode* removeElements(ListNode* head, int val) {
    if (!head) return NULL;
    if (!head->next && head->val != val) return head;
    if (!head->next && head->val == val) return NULL;
    ListNode* pN = NULL;
    ListNode* cN = head;
    ListNode* nN = head->next;
    return helpFunc(head, pN, cN, nN, val);
}