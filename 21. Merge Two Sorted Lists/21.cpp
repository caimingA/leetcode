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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode* p1 = l1;
       ListNode* p2 = l2;
       ListNode* newList = new ListNode(0);
       ListNode* pNew = newList;
       while(p1 != NULL && p2 != NULL){
           if(p1->val < p2->val){
               pNew->next = new ListNode(p1->val);
               p1 = p1->next;
           }else{
               pNew->next = new ListNode(p2->val);
               p2 = p2->next;
           }
           pNew = pNew->next;
       }
       if(p1 != NULL){
           while(p1 != NULL){
               pNew->next = new ListNode(p1->val);
               p1 = p1->next;
               pNew = pNew->next;
           }
       }
       if(p2 != NULL){
           while(p2 != NULL){
               pNew->next = new ListNode(p2->val);
               p2 = p2->next;
               pNew = pNew->next;
           }
       }
       return newList->next;
    }
};