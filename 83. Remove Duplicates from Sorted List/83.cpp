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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* pointer1 = head->next;
        ListNode* pointer2 = head;
        while(pointer1 != NULL){
            if(pointer1->val == pointer2->val){

            }else{
                pointer2->next = pointer1;
                pointer2 = pointer1;
            }
            if(pointer1->next == NULL){
                pointer2->next = NULL;
            }
            pointer1 = pointer1->next;
        }
        return head;
    }
};