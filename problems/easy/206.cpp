//Number: 206
//Name: Reverse Linked List
//Tags: linked list

// recursive
class Solution_1 {
public:
    ListNode* reverseHelper(ListNode* prev, ListNode* cur) {
        if (!cur) return prev;
        ListNode* temp = cur->next;
        cur->next = prev;
        return reverseHelper(cur, temp);
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        return reverseHelper(nullptr, head);
    }
};

// iterative

class Solution_2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* prev = nullptr;

        while (head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }
};

