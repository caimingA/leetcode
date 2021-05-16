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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > result;
        TreeNode* pointer = root;
        vector<TreeNode* > stackNodes;
        while(stackNodes.size() != 0 || pointer != NULL){
            if(pointer != NULL){//遍历左节点
                stackNodes.push_back(pointer);
                pointer = pointer -> left;
            }else{//遍历右节点
                TreeNode * now = stackNodes.back();
                stackNodes.pop_back();
                result.push_back(now -> val);
                pointer = now -> right;
            }
        }
        return result;
    }
};