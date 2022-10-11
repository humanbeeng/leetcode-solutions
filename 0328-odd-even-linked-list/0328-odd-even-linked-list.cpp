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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == nullptr or head -> next == nullptr) {
            return head;
        }
        
        ListNode* even = head -> next;
        ListNode* even_head = even;
        ListNode* odd = head;
        
        while(odd -> next and even -> next) {
            odd = odd -> next = even -> next;
            even = even -> next = odd -> next;
        }
        
        odd -> next = even_head;
        
        return head;
    }
};