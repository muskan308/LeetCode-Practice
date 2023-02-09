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
    ListNode* insert(ListNode *head, int val){
        ListNode *newnode = new ListNode(val);
        
        if(head == NULL){
            return newnode;
        }
        ListNode *newhead = head;
        while(head->next!=NULL){
            head = head->next;
        }
        head->next = newnode;
        return newhead;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                head = insert(head, list1->val);
                list1= list1->next;
            }else{
                head = insert(head, list2->val);
                list2 = list2->next;
            }
        }
        while(list1!=NULL){
             head = insert(head, list1->val);
             list1= list1->next;
        }
        while(list2!=NULL){
             head = insert(head, list2->val);
             list2= list2->next;
        }
        return head;
    }
};