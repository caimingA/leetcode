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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        if(root -> left == NULL && root -> right == NULL){
            if(root -> val == targetSum){
                return true;
            }else{
                return false;
            }
        }
        int sumLeft = 0;
        int sumRight = 0;
        TreeNode* now = root;
        queue<TreeNode* > treeq;
        TreeNode* newroot = new TreeNode(root->val);
        TreeNode* pointer = newroot;
        queue<TreeNode* > newTree;

        treeq.push(root);
        newTree.push(newroot);
        while(!treeq.empty()){
            now = treeq.front();
            pointer = newTree.front();
            treeq.pop();
            newTree.pop();
            if(now->left != NULL){
                treeq.push(now->left);
                sumLeft = pointer->val + now->left->val;
                TreeNode* newNode = new TreeNode(sumLeft);
                pointer->left = newNode;
                cout << "left->" << sumLeft << endl;
                newTree.push(newNode);
            }else{
                if(now->right == NULL && pointer->val == targetSum){
                    cout << sumLeft << endl;
                    return true;
                }
            }
            if(now->right != NULL){
                treeq.push(now -> right);
                sumRight = pointer->val + now->right->val;
                TreeNode* newNode = new TreeNode(sumRight);
                pointer->right = newNode;
                cout << "right->" << sumRight << endl;
                newTree.push(newNode);
            }else{
                if(now->left == NULL && pointer->val == targetSum){
                    cout << sumRight << endl;
                    return true;
                }
            }  
        }
        return false;
    }
};