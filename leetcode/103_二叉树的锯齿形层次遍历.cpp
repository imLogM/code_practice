//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//3
/// \
//  9  20
///  \
//   15   7
//返回锯齿形层次遍历如下：
//
//[
//[3],
//[20,9],
//[15,7]
//]

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) { return ret; }

        int layer = 0;
        queue<TreeNode*> q;
        int curLayerCount = 0;
        int nextLayerCount = 1;
        q.push(root);
        while (!q.empty()) {
            ++layer;
            curLayerCount = nextLayerCount;
            nextLayerCount = 0;
            vector<int> temp;
            while (curLayerCount-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                    ++nextLayerCount;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    ++nextLayerCount;
                }
            }
            if (layer %2 ==0) {
                reverse(temp.begin(), temp.end());
                ret.push_back(temp);
            } else {
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
