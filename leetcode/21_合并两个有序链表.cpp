//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) { return l2; }
        if (l2 == nullptr) { return l1; }

        // 根据第一个节点判断从哪个写到哪个
        if (l1->val <= l2->val) {
            return mergeBtoA(l1, l2);
        } else {
            return mergeBtoA(l2, l1);
        }

    }
    ListNode* mergeBtoA(ListNode* a, ListNode* b) {
        ListNode* ret = a;
        ListNode* pre = nullptr; ListNode* cur = a;
        while (b != nullptr) {
            if (cur==nullptr || cur->val > b->val) {
                pre->next = b;
                b=b->next;
                pre->next->next = cur;
                pre = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return ret;
    }
};
