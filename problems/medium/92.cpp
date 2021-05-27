// Number: 92
// Name: Reverse Linked List II
// Tags: linked list

// iterative ; time O(N) space O(1)
class Solution_0 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return head;
        ListNode* prevNode = nullptr;
        ListNode* curNode = head;
        ListNode* nextNode = head->next;
        for (int i = 1; i < left; ++i) {
            prevNode = curNode;
            curNode = nextNode;
            nextNode = nextNode->next;
        }
        ListNode* leftNode = prevNode; // will be pointing to the new head of the fragment
        for (int i = left; i < right; ++i) {
            ListNode* tempNode = nextNode->next;
            nextNode->next = curNode;
            if (prevNode != leftNode) {
                curNode->next = prevNode;
            }
            prevNode = curNode;
            curNode = nextNode;
            nextNode = tempNode;
        }
        // nextNode == right
        curNode->next = prevNode;
        if (leftNode) {
            leftNode->next->next = nextNode;
            leftNode->next = curNode;
        } else {
            head->next = nextNode;
            head = curNode;
        }       
        return head;
    }
};



