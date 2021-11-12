// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。


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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        return getDepth(root) != -1;
    }

    int getDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int leftDepth = getDepth(root -> left);
        int rightDepth = getDepth(root -> right);

        if(leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) {
            return -1;
        }else {
            return max(leftDepth, rightDepth) + 1;
        }
    }
};