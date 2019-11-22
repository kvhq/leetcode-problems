ListNode* middleNode(ListNode* head) {
    int listSize = 0;
    ListNode* tempNode = head;
    while (tempNode) {
        listSize++;
        tempNode = tempNode->next;
    }
    int middle = listSize / 2;
    int i = 1;
    tempNode = head;
    while (i <= middle) {
        tempNode = tempNode->next;
        i++;
    }
    return tempNode;
}
