//给定一个二叉树，返回它的中序 遍历。
//
//示例:
//
//输入: [1,null,2,3]
//1
//  \
//     2
//  /
//3
//
//输出: [1,3,2]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) { return res; }

        stack<TreeNode*> s;
        TreeNode* node = root;

        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            res.push_back(node->val);
            s.pop();
            node = node->right;
        }

        return res;
    }
};
