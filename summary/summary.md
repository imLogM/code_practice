# 1. 数组

## 1.1 排序

- Leetcode 217: 给定一个整数数组，判断是否存在重复元素。如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
  > 排序：O(nlogn)+O(1)；哈希：O(n)+O(n)

- Leetcode 219: 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
  > 维护大小为k的搜索树：O(nlogk)+O(k)；哈希：O(n)+O(k)

- Leetcode 220: 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。
  > 维护大小为k的搜索树：O(nlogk)+O(k)；以t做分桶：O(n)+O(k)

- Leetcode 287: （鸽子洞原理、抽屉原理）给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
  > 排序：O(nlogn)+O(1)；哈希：O(n)+O(n)；
  > 各元素归位：O(n)+O(1)；当数组不能被修改时，使用二分：O(nlogn)+O(1)；循环检测（转换为带环链表查环节点）：O(n)+O(1)

- Leetcode 905: 数组奇数排前面，偶数排后面
  > partition算法的变形

- Leetcode 169: 求众数（出现次数超过一半）
  > 排序: O(nlogn)+O(1)；哈希: O(n)+O(n)；partition: 利用众数一定为中位数的特性，O(n)+O(1)；摩尔投票: O(n)+O(1)

- Leetcode 229: 求出现次数超过1/3的数
  > 摩尔投票，每次一起删除3个不同的数，剩下的一定是候选

- Leetcode 295: 数据流求中位数
  > 最大最小堆

- TopK问题
  > partition: O(n)+O(1)；最小堆: O(nlogk)+O(k)

- Leetcode 493: 求逆序对数量

- Leetcode 327: 和在一定范围的区间的个数
  > dp + 归并

- Leetcode 349: 求两个数组的交集（数组含重复元素时，只输出一个）
  > 哈希: O(n)+O(n); 各自排序后归并: O(nlogn)+O(1)

- Leetcode 350: 求两个数组的交集（数组含重复元素时，输出多个）
  > 哈希: O(n)+O(n); 各自排序后归并: O(nlogn)+O(1)



## 2.2 查找

- Leetcode 153: 旋转排序数组找最小值（无重复元素）
  > 以数组第一个元素为判断锚点，二分查找

- Leetcode 33: 旋转排序数组找某个值（无重复元素）
  > 先找旋转轴点再二分；或者直接二分找

- Leetcode 81: 旋转排序数组找某个值（有重复元素）
  > 退化为顺序查找？；左边界缩减？

## 2. 字符串

- 将字符串中的空格替换为%20
  > O(n)+O(1)
  > 归并排序合并两个数组的思想

- Leetcode 151: 翻转字符串中的单词
  > 栈；两次翻转

- 旋转字符串：abcdefg -> cdefgab

## 3. 链表

- 从尾到头打印链表
  > 栈：O(n)+O(n)；翻转链表：O(n)+O(1)

- Leetcode 237: 删除链表节点
  > 尾节点是特殊情况

- Leetcode 83: 排序链表删除重复节点

- 快慢指针：如果链表中节点个数为偶数时，当快指针无法继续移动时，慢指针刚好指向中点；如果链表中节点个数为奇数时，当快指针走完，慢指针指向中点前一个节点。

    ```cpp
    while (fast->next && fast->next->next) {
        slow=slow->next;//slow指针每次走一步
        fast=fast->next->next;//fast指针每次走两步
    }
    ```

- Leetcode 141: 判断链表是否有环
  > 快慢指针：O(n)+O(1)；记录走过的节点：O(n)+O(n)

- Leetcode 142: 找链表环的入口
  > 先快慢指针判断有没有环，然后在相遇点和起点放两个指针同时走，再次相遇点为环入口

- Leetcode 21: 合并两个有序链表
  > 递归、迭代、哨兵节点

- Leetcode 23: 合并k个有序链表
  > 用堆优化：O(nlogk)+O(k)

- Leetcode 138: 带随机指针的链表的复制
  > 本质是图的拷贝，图的拷贝使用dfs+哈希来做，新旧节点交替的解法相当于节省了哈希所需要的空间

- Leetcode 160: 相交链表的公共节点


## 4. 树

- Leetcode 105: 前序和中序重建二叉树

- Leetcode 106: 后序和中序重建二叉树

- Leetcode 889: 前序和后序重建二叉树，任意符合的都可以
  > 为什么前序和后序不能唯一确定一棵树？

- Leetcode 112 113: 二叉树中是否存在和为某值的路径，并打印

- Leetcode 572: 判断一棵树是不是另一棵树的子树
  > 递归，本质是图的回溯法

- 对二叉树做镜像
  > 递归，相当于对每个有孩子节点的节点做镜像

- Leetcode 101: 判断二叉树是否对称
  > 递归，或者队列层次遍历

- Leetcode 255: 通过前序遍历序列判断是否二叉搜索树
  > 二叉搜索树的性质，递归；后序遍历也是相同解法

- Leetcode 331: 验证前序序列是否是二叉树
  > 方法1：图的入度和与出度和相等
  > 方法2：栈

- Leetcode 114: 二叉树前序遍历展开为链表
  > 递归

- Leetcode 102: 分层打印二叉树

- Leetcode 107: 反向分层打印二叉树
  > 用栈存储或用reverse

- Leetcode 103: Z字型打印二叉树
  > 两个栈

- Leetcode 993: 判断两个节点是否堂兄弟
  > 用哈希表记录节点的深度和父亲

- Leetcode 297: 二叉树的序列化与反序列化
  > 不使用"前序+中序"的原因是不支持数据流，且不能有重复节点；前序遍历+递归

- Leetcode 236: 树的最低公共祖先

- Leetcode 104: 二叉树的最大深度
  > 递归或迭代

- Leetcode 111: 二叉树的最小深度
  > 递归

- Leetcode 110: 判断二叉树是否平衡

## 5. 栈/队列

- Leetcode 232: 栈实现队列

- Leetcode 225: 队列实现栈

- Leetcode 155: 包含min函数的栈

- Leetcode 946: 判断栈的压栈序列和出栈序列是否对应
  > 模拟整个过程

- Leetcode 397: 字符串解码
  > 括号匹配问题

- Leetcode 239: 滑动窗口的最大值
  > 双向队列；dp

## 6. dp

- Leetcode 240: 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：每行的元素从左到右升序排列。每列的元素从上到下升序排列。
  > dp：O(m+n)+O(1)；如果条件更严格直接可转换为一维排序数组，则二分：O(log(m+n))+O(1)

- Leetcode 70: 跳台阶

- 如果跳台阶每次可以跳1~n阶呢？

- Leetcode 746: 每跳到一个台阶花费对应的cost，问cost最小的跳法

- 矩阵覆盖: 用2×1的矩形覆盖2×n的矩形，问有覆盖几种方法

- Leetcode 63: 机器人从左上角到右下角的路径有几条，中间有障碍物，只能向下或向右。
  > dp: O(n^2)+O(n^2)

- 把长n的绳子剪开，使各段乘积最大。

- Leetcode 44: 带'?'和'*'的通配符匹配

- Leetcode 53: 连续子数组最大和

- Leetcode 91: 将数字解码为字符串，有几种解法

- n个骰子点数之和的所有可能及出现概率

- Leetcode 121, 122, 123


## 7. 回溯/DFS

- Leetcode 79: 在矩阵中搜索单词是否存在

- Leetcode 212: 单词搜索 + Tire树

- 机器人可以上下左右移动，但不能进入一些格子，问机器人能到达多少格子

- Leetcode 10: 匹配正则表达式
  > 注意'.*'的情况，也可以dp解

- Leetcode 51 52: 八皇后问题

### 7.2 全排列/全组合

- Leetcode 46 47: 全排列
  > dfs；二进制位
  > 如果有重复字符，排序剪枝

- Leetcode 31: 下一个排列

- Leetcode 69: 全排列中的第k个
  > 数学公式

- Leetcode 77: 组合
  > dfs；找1个数的所有组合，再找2个数的所有组合

- Leetcode 29: sum为某个值的全部组合
  > dfs所有情况，判断

## 8. 位运算

- Leetcode 191: 二进制中1的个数
  > n & (n-1) 可以将最右边的1变为0，无论正负数，无论是否溢出

- Leetcode 231: 判断整数是否2的幂
  > n & (n-1) == 0

- Leetcode 326: 判断整数是否3的幂
  > 用整数范围内最大的3的幂被除这个数，看是否除尽

- Leetcode 342: 判断整数是否4的幂
  > 只有1个1，且在奇数位上

- 整数m要改变多少二进制位，才能得到整数n
  > c = m^n, 求c的1的个数

- Leetcode 136: 找出数组中只出现1次的数字

- Leetcode 137: 一个数字出现1次，其他数字出现3次，找出出现1次的数字
  > 二进制每个位各自累加，再每个位判断是否被3整除

- Leetcode 260: 两个数字出现1次，其他数字出现2次，找出现1次的数字
  > 先异或一遍，找到不为0的某一位，以该位是否为0将数组分成两部分

- Leetcode 389: 两个字符串有一个字符不同，其他字符相同但顺序不一致，找不同的字符
  > 异或

- 位运算实现加法

- 位运算交换两个变量，不使用额外的变量

## 9. 双指针

- Leetcode 3: 无重复字符的最长子串

- Leetcode 1: 数组中找=和为某个值的2个数

- Leetcode 15: 数组中找和为某个值的3个数

- Leetcode 11: 盛水最多的容器


## 10. 哈希

- 找出字符串中第一个只出现一次的字符

- 从第一个字符串中删除第二个字符串出现过的字母

- 删除字符串中重复的字母

- 判断是否为变位词（组成字母相同，顺序不同）

- 找字符流里第一个只出现一次的字符



## 10. 其它

- Leetcode 50: 快速幂
  > 用递归写简单

- Leetcode 69: 求平方根，保留整数
  > 二分

- 大数问题：相加、相乘
  > python？