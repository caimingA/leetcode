// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL

**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* rHead = nullptr;
        if(head == nullptr || head -> next == nullptr) {
            return head;
        }

        stack<ListNode* > st;
        ListNode* ptr = head;

        while(ptr) {
            st.push(ptr); 
            ListNode* now = ptr;
            ptr = ptr -> next;
            now -> next =  nullptr;
        }

        while(!st.empty()) {
            ListNode* now = st.top();
            // cout << now -> val << endl;
            if(rHead == nullptr) {
                rHead = now;
                ptr =rHead;
            }else {
                
                ptr -> next = now;
                // cout << now -> val << " with " <<ptr -> val << endl;
                ptr = now;
            }

            st.pop();
        }

        // ptr = rHead;
        // while(ptr) {
        //     cout << ptr -> val << endl;
        //     ptr = ptr -> next;
        // }

        return rHead;
    }
};