// 用两个栈实现一个队列。队列的声明如下，
// 请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
// (若队列中没有元素，deleteHead 操作返回 -1 )

class CQueue {
public:
    vector<int> inStack, outStack;
    CQueue() {
        while (!inStack.empty()) {
            inStack.pop_back();
        }
        while (!outStack.empty()) {
            outStack.pop_back();
        }
    }

    
    void appendTail(int value) {
        inStack.push_back(value);
    }
    
    int deleteHead() {
        if(outStack.empty()){
            if(inStack.empty()) {
                return -1;
            }else {
                for(int num : inStack) {
                    int temp = inStack.back();
                    inStack.pop_back();
                    outStack.push_back(temp);
                }
                int result = outStack.back();
                outStack.pop_back();
                return result;
            }
        }else {
            int result = outStack.back();
            outStack.pop_back();
            return result;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */