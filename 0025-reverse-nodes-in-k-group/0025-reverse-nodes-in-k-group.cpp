/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;
        ListNode* prev = dummy;
        ListNode* next = nullptr;

        // Count total number of nodes
        int count = 0;
        while (curr->next) {
            curr = curr->next;
            count++;
        }

        while (count >= k) {
            curr = prev->next;
            next = curr->next;
            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            // Move prev to the end of the reversed group
            prev = curr;
            count -= k;
        }

        return dummy->next;
    }
};
