// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode* > q;
        TreeNode* ptr = nullptr;

        q.push(root);

        while(!q.empty()) {
            int size = q.size(); 
            vector<int> temp;
            for(int i = 0; i < size; ++i) { // 控制循环的时候如果直接q.size()，会使循环的终止条件改变
                ptr = q.front();
                if(ptr -> left) q.push(ptr -> left);
                if(ptr ->right) q.push(ptr -> right);

                temp.push_back(ptr -> val);
                q.pop();

            }
            res.push_back(temp);
        }
        return res;
    }
};