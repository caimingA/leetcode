// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
        // queue<TreeNode* > q;
        deque<TreeNode* > deq;
        TreeNode* ptr = nullptr;
        int count = 0;
        deq.push_back(root);

        while(!deq.empty()) {
            vector<int> temp;
            if(count % 2 == 0) {
                int size = deq.size();
                for(int i = 0; i < size; ++i) {
                    ptr = deq.front();
                    deq.pop_front();
                    if(ptr -> left) deq.push_back(ptr -> left);
                    if(ptr -> right) deq.push_back(ptr -> right);

                    temp.push_back(ptr -> val);
                }
            }else {
                int size = deq.size();
                for(int i = 0; i < size; ++i) {
                    ptr = deq.back();
                    deq.pop_back();
                    if(ptr -> right) deq.push_front(ptr -> right);
                    if(ptr -> left) deq.push_front(ptr -> left);

                    temp.push_back(ptr -> val);    
                }
            }
            res.push_back(temp);
            ++count;
        }
        return res;
    }
};