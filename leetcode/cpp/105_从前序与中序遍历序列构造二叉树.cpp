//根据一棵树的前序遍历与中序遍历构造二叉树。
//
//注意:
//你可以假设树中没有重复的元素。
//
//例如，给出
//
//        前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7]
//返回如下的二叉树：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
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
    TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder,
                            int preorderBegin, int preorderEnd, int inorderBegin, int inorderEnd) {
        if (preorderBegin>=preorderEnd || inorderBegin>=inorderEnd) { return NULL; }

        TreeNode* root = new TreeNode(preorder[preorderBegin]);
        int inorderIndex = INT_MAX-1;
        for (int i=inorderBegin; i<inorderEnd; ++i) {
            if (inorder[i] == preorder[preorderBegin]) {
                inorderIndex = i;
                break;
            }
        }

        if (inorderIndex != INT_MAX-1) {
            root->left = buildTreeCore(preorder, inorder,
                                       preorderBegin+1, preorderEnd, inorderBegin, inorderIndex);
            root->right = buildTreeCore(preorder, inorder,
                                        preorderBegin+(inorderIndex-inorderBegin+1), preorderEnd, inorderIndex+1, inorderEnd);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) { return nullptr; }

        int preorderBegin = 0, inorderBegin = 0, preorderEnd = preorder.size(), inorderEnd = inorder.size();
        return buildTreeCore(preorder, inorder, preorderBegin, preorderEnd, inorderBegin, inorderEnd);
    }
};
