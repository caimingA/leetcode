// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

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
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        if(head == nullptr) return result;
        if(head -> next == nullptr) {
            result.push_back(head->val);
            return result;
        } 
        
        stack<int> st;

        ListNode* ptr = head;
        while(ptr) {
            // cout << ptr -> val << endl;
            st.push(ptr->val);
            ptr = ptr -> next;
        }

        while(!st.empty()) {
            int temp = st.top();
            result.push_back(temp);
            st.pop();
        }

        return result;
    }
};