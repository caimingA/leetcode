// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        TreeNode* ptr1 = nullptr;
        TreeNode* ptr2 = nullptr;

        q1.push(root);
        q2.push(root);

        while(!q1.empty()) {
            ptr1 = q1.front();
            ptr2 = q2.front();

            cout << ptr1 << "||" << ptr2 << endl;
            if(ptr1->val != ptr2->val) return false;

            q1.pop();
            q2.pop();

            if(ptr1->left) q1.push(ptr1->left);
            if(ptr1->right) q1.push(ptr1->right);

            if(ptr2->right) q2.push(ptr2->right);
            if(ptr2->left) q2.push(ptr2->left);
            

            if(ptr1->left != nullptr) {
                cout << "1" << endl;
                if(ptr2 -> right == nullptr) return false; 
            }else {
                cout << "2" << endl;
                if(ptr2 -> right != nullptr) return false;
            }

            if(ptr1->right != nullptr) {
                cout << "3" << endl;
                if(ptr2 -> left == nullptr) return false; 
            }else {
                cout << "4" << endl;
                if(ptr2 -> left != nullptr) return false;
            }
            
        }
        return true;
    }
};