// 给定一棵二叉搜索树，请找出其中第k大的节点。

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
    int kthLargest(TreeNode* root, int k) {
        TreeNode* ptr = root;
        stack<TreeNode* > s;
        vector<int> record;

        while(ptr || !s.empty()) {
            if(ptr) {
                s.push(ptr);
                ptr = ptr -> right;
            }else {
                ptr = s.top();
                record.push_back(ptr -> val);
                s.pop();
                ptr = ptr -> left;
            }
        }
        for(int i : record) {
            cout << i << endl;
        }
        return record[k - 1];
    }
};