// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> temp;
        temp.push_back(root -> val);
        backtrack(root, target - root -> val, res, temp);
        return res;
    }

    void backtrack(TreeNode* pos, int target, vector<vector<int>>& res, vector<int>& temp) {
        cout << pos -> val << endl;
        if(pos -> left == nullptr && pos -> right == nullptr) {
            if(target == 0) {
                res.push_back(temp);
                return ;
            }else {
                return ;
            }
        }
        for(int i = 0; i < 2; ++i) {
            if(i == 0 && pos -> left) {
                temp.push_back(pos -> left -> val);
                backtrack(pos -> left, target - pos -> left -> val, res, temp);
                temp.pop_back();
            }
            if(i == 1 && pos -> right) {
                temp.push_back(pos -> right -> val);
                backtrack(pos -> right, target - pos -> right -> val, res, temp);
                temp.pop_back();
            }
        }
    }
};