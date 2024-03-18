/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
 following the next pointer.Internally, pos is used to denote the index of the node that tail's 
 next pointer is connected to.
 Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
*/
class Solution {
    
public:
    /bool hasLoop(ListNode *head) {
    // Initialize slow and fast pointers
    Node* slow = head;
    Node* fast = head;
 
    // Loop until the end of the list is reached
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow pointer one step forward
        slow = slow->next;
        // Move fast pointer two steps forward
        fast = fast->next->next;
 
        // Check if slow and fast pointers meet
        if (slow == fast) {
            // A loop is found, return true
            return true;
        }
    }
 
    // No loop is found, return false
    return false;
}
};