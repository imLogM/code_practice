//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1==nullptr) { return l2; }
        else if (l2==nullptr) { return l1; }

        int sum = 0;
        bool flag = false;
        ListNode* res = nullptr;
        ListNode* cur = nullptr;
        while (l1!=nullptr || l2!=nullptr || flag!=false) {
            sum = 0;
            if (l1!=nullptr) { sum += l1->val; l1 = l1->next; }
            if (l2!=nullptr) { sum += l2->val; l2 = l2->next; }
            sum += (int)flag;
            if (sum >= 10) {
                flag = true;
                sum %= 10;
            } else {
                flag = false;
            }
            if (cur == nullptr) {
                cur = new ListNode(sum);
                res = cur;
            } else {
                cur->next = new ListNode(sum);
                cur = cur->next;
            }
        }
        return res;
    }
};