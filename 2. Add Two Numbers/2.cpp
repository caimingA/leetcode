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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* resultList = new ListNode(0);
        ListNode* p0 = resultList;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while(p1 != NULL || p2 != NULL){
            int a = p1 == NULL ? 0 : p1->val;
            int b = p2 == NULL ? 0 : p2->val;
            int add = a + b + carry;
            carry = add / 10;
            p0->next = new ListNode(add % 10);
            if(p1 != 0){
                p1 = p1->next;
            }
            if(p2 != 0){
                p2 = p2->next;
            }
            p0 = p0->next;
        }
        if(carry == 1){
            p0->next = new ListNode(1);
        }
        return resultList->next;
    }
};