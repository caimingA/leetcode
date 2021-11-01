// 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

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
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;

        queue<TreeNode*> q;
        TreeNode* ptr = nullptr;

        q.push(root);
        while(!q.empty()) {
            ptr = q.front();
            q.pop();
            TreeNode* leftNode = ptr->left;
            TreeNode* rightNode = ptr->right;

            if(leftNode) {
                q.push(leftNode);
            }
            if(rightNode) {
                q.push(rightNode);
            }
            ptr->left = rightNode;
            ptr->right = leftNode;

        }
        return root;
    }
};