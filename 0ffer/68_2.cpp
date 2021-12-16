// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root) return root;

        vector<TreeNode*> pList = findAnc(root, p);
        vector<TreeNode*> qList = findAnc(root, q);

        while(pList.size() != qList.size()) {
            if(pList.size() > qList.size()) {
                pList.pop_back();
            }else if(pList.size() < qList.size()) {
                qList.pop_back();
            }else {
                continue;
            }
        }
        while(!pList.empty()) {
            TreeNode* pTop = pList.back();
            TreeNode* qTop = qList.back();

            if(pTop -> val == qTop -> val) {
                return pTop;
            }

            pList.pop_back();
            qList.pop_back();

        }
        return root;
    }
    vector<TreeNode* > findAnc(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> ancList;
        TreeNode* ptr = root;
        TreeNode* pre = nullptr;
        while(ptr || !ancList.empty()) {
            if(ptr) {
                ancList.push_back(ptr);
                ptr = ptr -> left;
            }else {
                ptr = ancList.back();
                if(ptr -> right && ptr -> right != pre) {
                    ptr = ptr -> right;
                    ancList.push_back(ptr);
                    ptr = ptr -> left;
                }else {
                    if(ptr->val == target -> val) {
                        return ancList;
                    }
                    ancList.pop_back();
                    pre = ptr;
                    ptr = nullptr;
                }
            }
        }

        return ancList;
    } 
};