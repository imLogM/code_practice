#include <iostream>

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode() : val(0), pLeft(nullptr), pRight(nullptr) {}
};

BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, int k) {
    if (pRoot->pLeft != nullptr) {
        return KthNode(pRoot->pLeft, k);
    }
    printf("%d", pRoot->val);

    if (pRoot->pRight != nullptr) {
        return KthNode(pRoot->pRight, k);
    }

}