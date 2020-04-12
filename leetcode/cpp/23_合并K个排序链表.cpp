//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例:
//
//输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Comp {
    bool operator() (const pair<int, ListNode*> a, const pair<int, ListNode*> b) {
        return (a.second->val) > (b.second->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = (int)lists.size();
        if (k<=0) { return nullptr;}

        ListNode* pHead = new ListNode(-1);
        ListNode* pMerged = pHead;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Comp> minQ;

        for (int i=0; i<k; ++i) {
            if (lists[i] != nullptr) {
                ListNode* temp = lists[i];
                lists[i] = temp->next;
                temp->next = nullptr;
                minQ.push(pair<int, ListNode*>(i, temp));
            }
        }

        while (!minQ.empty()) {
            ListNode* temp = minQ.top().second;
            int i = minQ.top().first;
            minQ.pop();
            pMerged->next = temp;
            pMerged = temp;
            if (lists[i] != nullptr) {
                ListNode* temp2 = lists[i];
                lists[i] = lists[i]->next;
                temp2->next = nullptr;
                minQ.push(pair<int, ListNode*>(i, temp2));
            }
        }

        ListNode* result = pHead->next;
        delete pHead;
        pHead = nullptr;
        return result;
    }
};
