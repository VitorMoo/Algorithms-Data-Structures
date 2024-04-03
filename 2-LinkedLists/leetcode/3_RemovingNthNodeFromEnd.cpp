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
        if (head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;              //creating the pointers
        ListNode* temp = nullptr;

        for (int i = 0; i < n; ++i) {       //calculates the number of steps that fast will move
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;         
        }

        if (fast == nullptr) {     //verifies if the fast pointer reached the end of the list during the process to move fast n times
            temp = head;/          ///can be changed to a dummy node
            head = head->next;
            delete temp;
            return head;
        }

        while (fast->next != nullptr) {
            slow = slow->next;              //move fast and slow by one step
            fast = fast->next;
        }

        temp = slow->next;
        slow->next = slow->next->next;      //slow->next will be the node that we want to remove
        delete temp;                        //so we say that temp is equal to the node that we want to re   move
        return head;                        //and slow->next is equal to next next, connecting the node and removing the temp node
    }
};