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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr or head -> next == nullptr) {
            delete(head);
            return nullptr;
        }
        
        ListNode* fast = head, *prev = nullptr, *slow = head;
        
        for(int i = 0; i < n; i++) { // to accomodate for 1th indexing
            fast = fast -> next;
        }
        
        if(fast == nullptr) { //ie n = n_nodes, delete the n_nodes'th from end, which means to delete the first node
            head = head -> next;
            return head;
        } 
        
        while(fast) {
            fast = fast -> next;
            prev = slow;
            slow = slow -> next;
        }
        
        prev -> next = slow -> next;
        delete(slow);
        
        
        
        return head;
        
    }
};