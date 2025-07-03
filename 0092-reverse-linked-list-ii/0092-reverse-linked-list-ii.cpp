class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;

        // Create a dummy node to simplify edge cases (like reversing from head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Traverse to the node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse the sublist from 'left' to 'right'
        ListNode* curr = prev->next;
        ListNode* next = nullptr;

        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};
