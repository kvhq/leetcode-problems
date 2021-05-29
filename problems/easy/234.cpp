// Number: 234
// Name: Palindrome Linked List
// Tags: linked list

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int counter = 0;
        ListNode* curNode = head;
        while (curNode) {
            counter++;
            curNode = curNode->next;
        }
        ListNode* prevNode = nullptr;
        curNode = head;
        int leftPartEnd = counter / 2 - 1;
        ListNode* nextNode = head->next;
        for (int i = 0; i <= leftPartEnd; ++i) {
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
            nextNode = nextNode->next;
        }
        if (counter % 2 != 0) curNode = nextNode;
        while (curNode) {
            if (curNode->val != prevNode->val) return false;
            curNode = curNode->next;
            prevNode = prevNode->next;
        }
        return true;
    }
};

