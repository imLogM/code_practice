//中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
//
//例如，
//
//[2,3,4] 的中位数是 3
//
//[2,3] 的中位数是 (2 + 3) / 2 = 2.5
//
//设计一个支持以下两种操作的数据结构：
//
//void addNum(int num) - 从数据流中添加一个整数到数据结构中。
//double findMedian() - 返回目前所有元素的中位数。
//示例：
//
//addNum(1)
//addNum(2)
//findMedian() -> 1.5
//addNum(3)
//findMedian() -> 2
//进阶:
//
//如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
//如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxQ.empty() || num < maxQ.top()) {
            maxQ.push(num);
        } else {
            minQ.push(num);
        }
        //调整两个堆中的元素数量
        while (maxQ.size() < minQ.size()) {
            int temp = minQ.top();
            minQ.pop();
            maxQ.push(temp);
        }
        while (maxQ.size() > minQ.size()+1) {
            int temp = maxQ.top();
            maxQ.pop();
            minQ.push(temp);
        }
    }

    double findMedian() {
        if (minQ.size() == maxQ.size()) {
            return 1.0 * (minQ.top() + maxQ.top()) / 2.0;
        } else {
            return (double)maxQ.top();
        }
    }

    priority_queue<int, vector<int>, less<int>> maxQ;   //大顶堆
    priority_queue<int, vector<int>, greater<int>> minQ;    //小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */