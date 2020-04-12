//请判断一个链表是否为回文链表。
//
//示例 1:
//
//输入: 1->2
//输出: false
//示例 2:
//
//输入: 1->2->2->1
//输出: true
//进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？


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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) { return true; }
        if (head->next == nullptr) { return true; }
        // 快慢指针找中点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 翻转中点后的链表
        ListNode *pre=nullptr, *cur=slow;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur; cur = tmp;
        }
        ListNode* tail = pre;


        // 比较是否相同
        while (tail!=nullptr && head!=nullptr) {
            if (tail->val != head->val) { return false; }
            tail = tail->next;
            head = head->next;
        }
        //有必要的话，就恢复原链表
        return true;
    }
};