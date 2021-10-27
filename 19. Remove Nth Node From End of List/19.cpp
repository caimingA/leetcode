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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode* ptr = head;
        num++;
        while(ptr->next){
            ptr = ptr->next;
            num++;
        }
        if(num == 1 && n == 1) return nullptr;
        
        int index = num - n;
        if(num == n) return head->next;

        ptr = head;
        num = 0;
        while(ptr->next && num < index - 1){
            ptr = ptr->next;
            num++;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};
