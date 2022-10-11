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
        
        ListNode* even_head = head -> next;
        ListNode* temp = even_head;
        ListNode* odd_head = head;
        
        while(odd_head -> next and even_head -> next) {
            odd_head = odd_head -> next = even_head -> next;
            even_head = even_head -> next = odd_head -> next;
        }
        
        odd_head -> next = temp;
        
        return head;
    }
};