// Number: 876
// Name: Middle of the linked list
// Tags: linked list

ListNode* middleNode(ListNode* head) {
    ListNode* middle = head;
    ListNode* last = head;
    while (last != NULL && last->next != NULL) {
        middle = middle->next;
        last = last->next->next;
    }
    return middle;
}
