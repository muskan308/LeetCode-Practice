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
        ListNode* tempA = headA;
        ListNode *tempB = headB; 
       // int l1 = 0, l2 = 0; 
        while(!(tempA ==NULL && tempB==NULL)){
            
            if(tempA == NULL) tempA = headB;
            if(tempB == NULL) tempB = headA;
            
              if(tempA == tempB) return tempA; 
                tempA = tempA->next;
            
            
            
                tempB = tempB->next;
            
        }
    
        return NULL;
    }
};