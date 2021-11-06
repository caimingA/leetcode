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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL){
            return false;
        }
        if(q == NULL){
            return false;
        }
        TreeNode* pointer1 = p;
        TreeNode* pointer2 = q;
        queue<TreeNode* > queue1;
        queue<TreeNode* > queue2;
        queue1.push(p);
        queue2.push(q);
        while(!queue1.empty() && !queue2.empty()){
            TreeNode* p1 = queue1.front();
            TreeNode* p2 = queue2.front();
            cout << p1->val << "||" << p2->val << endl;
            if(p1->val != p2->val){
                return false;
            }
            if(p1->left != NULL){
                queue1.push(p1->left);
                if(p2->left != NULL){
                    queue2.push(p2->left);
                }else{
                    return false;
                }       
            }else{
                if(p2->left != NULL){
                    queue2.push(p2->left);
                }
            }
            if(p1->right != NULL){
                queue1.push(p1->right);
                if(p2->right != NULL){
                    queue2.push(p2->right);
                }else{
                    return false;
                }
                
            }else{
                if(p2->right != NULL){
                    queue2.push(p2->right);
                }
            }
            queue1.pop();
            queue2.pop();
            
        }
        if(!queue1.empty() || !queue2.empty()){
            return false;
        }
        return true;
    }
};