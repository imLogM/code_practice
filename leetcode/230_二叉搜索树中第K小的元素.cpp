//给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
//
//说明：
//你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
//
//示例 1:
//
//输入: root = [3,1,4,null,2], k = 1
//3
/// \
// 1   4
//\
//   2
//输出: 1
//示例 2:
//
//输入: root = [5,3,6,2,4,null,null,1], k = 3
//5
/// \
//     3   6
/// \
//   2   4
///
//1
//输出: 3

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
    void inOrder(TreeNode* root, int& res, int& k) {
        if (root == nullptr) {return;}
        if (k<=0) {return;}

        inOrder(root->left, res, k);
        if (k<=0) {return;}

        res = root->val;
        --k;
        if (k<=0) {return;}

        inOrder(root->right, res, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res;
        inOrder(root, res, k);
        return res;
    }
};