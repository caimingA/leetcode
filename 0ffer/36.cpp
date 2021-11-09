// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

// 我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。
// 对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

// 特别地，我们希望可以就地完成转换操作。
// 当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。
// 还需要返回链表中的第一个节点的指针。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* head = nullptr;
        if(root -> left == nullptr && root -> right == 0) {
            head = root;
            root -> left = root;
            root -> right = root;
            return head;
        }
        stack<Node* > s;
        vector<Node* > record;
        Node* ptr = root;
        while(ptr || !s.empty()) {
            if(ptr) {
                s.push(ptr);
                ptr = ptr -> left;
            }else {
                ptr = s.top();
                s.pop();
                // cout << ptr -> val << endl;
                record.push_back(ptr);
                ptr = ptr->right;
            }
        }
        

        for(int i = 0; i < record.size(); ++i) {
            if(i == 0) {
                head = record[i];
                record[i] -> left = record[record.size() - 1];
                record[i] -> right = record[i + 1];
            }else if(i == record.size() - 1) {
                record[i] -> right = record[0];
                record[i] -> left = record[i - 1];
            }else {
                record[i] -> right = record[i + 1];
                record[i] -> left = record[i - 1];
            }
        }
        return head;
    }
};