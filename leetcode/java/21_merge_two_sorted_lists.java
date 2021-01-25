//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
//Example:
//
//Input: 1->2->4, 1->3->4
//Output: 1->1->2->3->4->4
//

// 方法：迭代法，时间复杂度O(n),空间复杂度O(1),也可以使用递归法
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // 生成一个哨兵节点
        ListNode sentinelNode = new ListNode(-1);
        ListNode tempNode = sentinelNode;
        // 开始合并
        while (l1!=null || l2!=null) {
            if (l1!=null && (l2==null || l1.val<l2.val)) {
                tempNode.next = l1;
                l1 = l1.next;
                tempNode = tempNode.next;
            }
            if (l2!=null && (l1==null || l1.val>=l2.val)) {
                tempNode.next = l2;
                l2 = l2.next;
                tempNode = tempNode.next;
            }
        }
        // 返回结果
        return sentinelNode.next;
    }
}
