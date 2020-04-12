//给定一个非空二叉树，返回其最大路径和。
//
//本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
//
//示例 1:
//
//输入: [1,2,3]
//
//1
/// \
//     2   3
//
//输出: 6
//示例 2:
//
//输入: [-10,9,20,null,null,15,7]
//
//-10
/// \
//  9  20
///  \
//   15   7
//
//输出: 42

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
    int postOrder(TreeNode* root, int& maxSum) {
        //路径中出现负值时可以舍弃该路径，重值路径最大值为0
        //动态规划，从下至上后序遍历，每个节点记录以该节点为根的二叉树树的最大路径和
        //但注意每次传给上一层的父节点的值是root + left 或 root + right
        if (root == nullptr) { return 0; }

        int l = postOrder(root->left, maxSum);
        int r = postOrder(root->right, maxSum);
        l = (l<0)? 0 : l;
        r = (r<0)? 0 : r;
        // printf("l=%d, r=%d, root=%d, res=%d\n", l, r, root->val, res);
        int maxCur = l + r + root->val;
        maxSum = max(maxSum, maxCur);
        int res = max(l + root->val, r + root->val);
        return res;
    }
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) { return 0; }
        int maxSum = INT_MIN;
        postOrder(root, maxSum);
        return maxSum;
    }
};