// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

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
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        while(ptr1 || ptr2) {
            if(ptr1 == nullptr) {
                ptr -> next = ptr2;
                break;
            }else if(ptr2 == nullptr) {
                ptr -> next = ptr1;
                break;
            }else {
                if(ptr1 -> val > ptr2 -> val) {
                    ptr -> next = ptr2;
                    ptr2 = ptr2 -> next;
                    ptr = ptr -> next;
                    ptr -> next = nullptr;
                }else {
                    ptr -> next = ptr1;
                    ptr1 = ptr1 -> next;
                    ptr = ptr -> next;
                    ptr -> next = nullptr;
                }
            }
        }
        return head->next;
    }
};