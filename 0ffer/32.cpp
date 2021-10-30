// DFS

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* ptr = nullptr;

        while(!q.empty()) {
            ptr = q.front();
            if(ptr -> left) q.push(ptr -> left);
            if(ptr ->right) q.push(ptr -> right);

            result.push_back(ptr -> val);
            q.pop();
        }
        return result;

    }
};