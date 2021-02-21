// Number: 1265
// Name: Print Immutable Linked List in Reverse
// Tags: Recursive

void printLinkedListInReverse(ImmutableListNode* head) {
    auto nextNode = head->getNext();
    if (nextNode) {
        printLinkedListInReverse(nextNode);
    }
    head->printValue();
    return;
}

