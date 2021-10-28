// 请实现 copyRandomList 函数，复制一个复杂链表。
// 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
// 还有一个 random 指针指向链表中的任意节点或者 null。

// https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) {
            Node * res = new Node(head -> val);
            if(head -> random) {
                res -> random = res;
            }
            return res;
        }

        Node* res = new Node(head -> val); // 结果的头节点
        Node* ptr = head; // 遍历原链表
        Node* ptrCopy = res; // 遍历新链表
        
        map<Node*, Node*> hashmap; // 新老链表的对应
        hashmap[head] = res;

        while(ptr -> next) { // 头节点已经定了，用-> next的形式进行循环控制
            Node* temp = new Node(ptr -> next -> val);
            ptrCopy -> next = temp;
            hashmap[ptr -> next] = ptrCopy -> next;
            ptr = ptr -> next;
            ptrCopy = ptrCopy -> next;
        }

        for(auto it : hashmap) {
            Node* from = it.first;
            Node* to = from -> random;

            it.second -> random = hashmap[to];
        }


        // 测试next是否正确输出了。
        // ptrCopy = res;
        // while(ptrCopy) {
        //     cout << ptrCopy -> val << endl;
        //     ptrCopy = ptrCopy -> next;
        // }

        return res;
    }
};