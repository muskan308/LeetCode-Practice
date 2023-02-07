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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        if(head->next == NULL) return false;
        
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next){
            slow = slow->next;
            //if(fast->next == NULL) return false;
            fast = fast->next->next;
            
            if(slow == fast) return true;
        }
        return false;
    }
};