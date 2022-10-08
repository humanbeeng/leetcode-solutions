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
    ListNode* reverseList(ListNode* head) {
//         if(head == nullptr || head -> next == nullptr) {
//             return head;
//         }
        
//         ListNode* reversed_head = reverseList(head -> next);
//         head -> next -> next = head;
//         head -> next = nullptr;
        
//         return reversed_head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        
        while(curr) {
            ListNode* temp = curr -> next;
            
            curr -> next = prev;
            
            prev = curr;
            
            curr = temp;
            
        }
        
        return prev;
    }
};