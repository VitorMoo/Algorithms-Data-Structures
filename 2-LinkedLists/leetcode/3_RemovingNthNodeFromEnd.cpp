/*Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 */


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = nullptr;

        for (int i = 0; i < n; i++) {
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
        }

        ListNode* prev = nullptr;

        while (fast != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if (prev != nullptr) {
            temp = prev->next;
            prev->next = prev->next->next;
            delete temp;
        } else {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        return head;
    }
};
