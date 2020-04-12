//请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
//
//示例:
//
//你可以将以下二叉树：
//
//1
/// \
//  2   3
/// \
//    4   5
//
//序列化为 "[1,2,3,null,null,4,5]"
//提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
//
//说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) { return "null,"; }

        deque<TreeNode*> q;
        q.push_back(root);
        string data = "";

        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop_front();
            if (tmp != nullptr) {
                data += to_string(tmp->val) + ',';

                q.push_back(tmp->left);
                q.push_back(tmp->right);
            } else {
                data += "null,";
            }
        }

        return data;
    }



    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null,") {return nullptr;}

        //取到根节点
        deque<TreeNode* > q;
        string tmpStr = "";
        int i = 0;
        while (data[i] != ',') {
            tmpStr += data[i];
            ++i;
        }
        ++i;
        TreeNode* root = new TreeNode(stoi(tmpStr));
        q.push_back(root);
        while ( !q.empty() ) {
            // 解析节点val
            string tmpStr1 = "";
            while (data[i] != ',') {
                tmpStr1 += data[i];
                ++i;
            }
            ++i;
            string tmpStr2 = "";
            while (data[i] != ',') {
                tmpStr2 += data[i];
                ++i;
            }
            ++i;

            //添加左右孩子
            TreeNode* tmpNode = q.front();
            q.pop_front();
            if (tmpStr1 != "null") {
                tmpNode->left = new TreeNode(stoi(tmpStr1));
                q.push_back(tmpNode->left);
            }
            if (tmpStr2 != "null") {
                tmpNode->right = new TreeNode(stoi(tmpStr2));
                q.push_back(tmpNode->right);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));