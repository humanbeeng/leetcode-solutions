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
       
        if(head -> next == nullptr or head == nullptr) {
            delete(head);
            return nullptr;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        
        while(fast and fast -> next) {
            fast = fast -> next -> next;
        
            slow = slow -> next;
        }
        
        if(slow -> next) {
            slow -> val = slow -> next -> val;
            ListNode* temp = slow -> next;
            slow -> next = slow -> next -> next;
            delete(temp);
        } else {
            head -> next = nullptr;
            delete(head -> next);
        }
        return head;
    }
};