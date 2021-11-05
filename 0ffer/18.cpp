// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

// 返回删除后的链表的头节点。

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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head->next;
        ListNode* ptr = head;
        while(ptr -> next) {
            if(ptr->next->val == val) {
                ptr->next = ptr -> next -> next;
                break;
            }else {
                ptr = ptr -> next;
            }
        }
        return head;
    }
};