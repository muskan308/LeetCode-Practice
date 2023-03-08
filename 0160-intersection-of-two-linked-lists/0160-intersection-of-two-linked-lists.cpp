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
        int l1 = 0, l2 = 0; 
        while(tempA !=NULL || tempB!=NULL){
            if(tempA!=NULL) {
                l1++;
                tempA = tempA->next;
            }
            if(tempB!=NULL){
                l2++;
                tempB = tempB->next;
            }
        }
        tempA = headA, tempB = headB;
        
        if(l1 > l2){
            while(l1 > l2){
                tempA = tempA->next;
                l1--;
            }
        }else{
            while(l1 < l2){
                tempB = tempB->next;
                l2--;
            }
        }
        
        while(tempA !=NULL){
            if(tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};