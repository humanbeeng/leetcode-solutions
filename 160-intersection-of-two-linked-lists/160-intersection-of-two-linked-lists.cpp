/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA; ListNode* ptrB = headB;
        
        // ptrA == ptrB == nullptr or ptrA == ptrB == some value
        while(ptrA != ptrB) {
            
            if(ptrA == nullptr) ptrA = headB;
            else ptrA = ptrA -> next;
            
            if(ptrB == nullptr) ptrB = headA;
            else ptrB = ptrB -> next;
            
        }
        
        return ptrA;
    }
};