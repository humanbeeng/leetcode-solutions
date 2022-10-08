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
    
    ListNode* findMid(ListNode* head) {
        if(head == nullptr or head -> next == nullptr) {
            return head;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast and fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr or head -> next == nullptr) {
            return head;
        }
        
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
    
    bool compareLists(ListNode* head_a, ListNode* head_b) {
        while(head_b) {
            if(head_a -> val != head_b -> val) {
                return false;
            }
            head_a = head_a -> next;
            head_b = head_b -> next;
        }
        
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMid(head);
        
        ListNode* reversed_head = reverseList(mid);
        
        return compareLists(head, reversed_head);
    }
};