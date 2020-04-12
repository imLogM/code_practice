//示例：
//输入：
//{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
//
//解释：
//节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
//节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
//
//
//提示：
//
//你必须返回给定头的拷贝作为对克隆列表的引用。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) { return nullptr; }

        //在原链表中复制出新链表
        Node* oldListNode = head;
        while(true) {
            Node* newListNode = new Node();
            newListNode->val = oldListNode->val;
            newListNode->next = oldListNode->next;
            newListNode->random = oldListNode->random;
            oldListNode->next = newListNode;

            oldListNode = newListNode->next;
            if (oldListNode == nullptr) {
                break;
            }
        }

        //调整新链表的random指针
        Node* newListNode = head->next;
        while(true) {
            newListNode->random = (newListNode->random != nullptr) ? (newListNode->random->next) : (nullptr);
            if (newListNode->next == nullptr) {
                break;
            } else {
                newListNode = newListNode->next->next;
            }
        }

        //分离新旧链表
        oldListNode = head;
        newListNode = head->next;
        Node* newList = head->next;
        while(true) {
            if (newListNode->next == nullptr) {
                oldListNode->next = nullptr;
                break;
            }
            oldListNode->next = newListNode->next;
            newListNode->next = newListNode->next->next;
            oldListNode = oldListNode->next;
            newListNode = newListNode->next;
        }

        return newList;
    }
};