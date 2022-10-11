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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr or head -> next == nullptr) {
            delete(head);
            return nullptr;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = slow;
        
        while(fast and fast -> next) {
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
        
        prev -> next = slow -> next;
        delete(slow);
        
        return head;
        
    }
};