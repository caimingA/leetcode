// 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 0;
        TreeNode* ptr = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(ptr || !q.empty()) {
            int num = q.size();
            for(int i = 0; i < num; ++i) {
                ptr = q.front();
                cout << ptr -> val << endl;;
                q.pop();
                
                if(ptr -> left) q.push(ptr -> left);
                if(ptr -> right) q.push(ptr -> right);  
            }
            ptr = nullptr;
            ++depth;
        }
        return depth;
    }
};