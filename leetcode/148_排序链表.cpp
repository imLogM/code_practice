//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
//
//示例 1:
//
//输入: 4->2->1->3
//输出: 1->2->3->4
//示例 2:
//
//输入: -1->5->3->4->0
//输出: -1->0->3->4->5


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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) { return nullptr; }
        else if (list1 && !list2) { return list1; }
        else if (!list1 && list2) { return list2; }

        ListNode* head;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* node = head;
        while (list1 || list2) {
            if (list1 && (!list2 || list1->val <= list2->val)) {
                node->next = list1;
                node = node->next;
                list1 = list1->next;
            }

            if (list2 && (!list1 || list1->val > list2->val)) {
                node->next = list2;
                node = node->next;
                list2 = list2->next;
            }
        }
        node->next = nullptr;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return head; }   // 列表里只有一个数，直接返回

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list1 = head;
        ListNode* list2 = slow;
        pre->next = nullptr;

        list1 = sortList(list1);
        list2 = sortList(list2);

        return merge(list1, list2);
    }

};

