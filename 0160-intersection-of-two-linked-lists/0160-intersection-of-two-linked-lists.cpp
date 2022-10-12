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
        ListNode* pa = headA; ListNode* pb = headB;
        
        while(pa != pb) {
            
            if(pa == nullptr) {
                pa = headB;
            } else {
                pa = pa -> next;
            }
            
            if(pb == nullptr) {
                pb = headA;
            } else {
                pb = pb -> next;
            }
            
            
        }
        
//         after while loop exits, due to pa = pb, we know that wither pa and pb would both be pointing
//         to nullptr(reached end) or pa and pb would be pointing to the intersected point
        
        return pa;
    }
};