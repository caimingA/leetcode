// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

// B是A的子结构， 即 A中有出现和B相同的结构和节点值。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;

        queue<TreeNode*> q;
        TreeNode* ptr = nullptr;
        q.push(A);
        while(!q.empty()) {
            ptr = q.front();
            cout << "out: " <<ptr->val << endl;
            q.pop();
            if(ptr->val == B->val) {
                if(isSubEqual(ptr, B)) return true;
            }

            if(ptr->left) q.push(ptr->left);
            if(ptr->right) q.push(ptr->right);
        } 
        return false;

    }

    bool isSubEqual(TreeNode* A, TreeNode* B) { //original, template
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(A);
        q2.push(B);

        TreeNode* ptr1 = nullptr;
        TreeNode* ptr2 = nullptr;

        while(!q2.empty()) {
            ptr1 = q1.front();
            ptr2 = q2.front();
            cout << "in: " <<ptr2->val << endl;

            q1.pop();
            q2.pop();

            if(ptr1->val != ptr2 -> val) return false;

            if(ptr2->left) {
                if(ptr1 -> left == nullptr) return false;
                q1.push(ptr1->left);
                q2.push(ptr2->left);
            }

            if(ptr2 -> right) {
                if(ptr1->right == nullptr) return false;
                q1.push(ptr1->right);
                q2.push(ptr2->right);
            }
        }
        return true;
    }
};