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
        
        for(int i = 0; i < n - 1; i++) { // to accomodate for 1 based indexing
            fast = fast -> next;
        }
        
        if(fast == nullptr) { //ie n = n_nodes, delete the n_nodes'th from end, which means to delete the first node
            head = head -> next;
            return head;
        } 
        
        while(fast -> next) { // halts at last node
            fast = fast -> next;
            prev = slow;
            slow = slow -> next;
        }
        
        if(prev != nullptr) { 
            // when n = 2 and it is currently pointing to first node of the list, as in [1,2] n = 2. then prev would be null
            // and there should be a check for this.
            prev -> next = slow -> next;
            delete(slow);
        } else {
            head = head -> next;
        }
        
        
        return head;
        
    }
};