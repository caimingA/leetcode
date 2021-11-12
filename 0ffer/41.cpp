// 双优先队列的使用
// greater是指最小堆
// less是值最大堆

class MedianFinder {
public:
    /** initialize your data structure here. */
    // 最大堆，存储左边一半的数据，堆顶为最大值
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // 最小堆， 存储右边一半的数据，堆顶为最小值
    priority_queue<int, vector<int>, greater<int>> minHeap;


    MedianFinder() {

    }
    
    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            minHeap.push(num);
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        } else {
            maxHeap.push(num);
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            return maxHeap.top()*1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */