// 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
// 调用 min、push 及 pop 的时间复杂度都是 O(1)。


// 单调栈
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> oriStack;
    vector<int> minStack;
    MinStack() {
        for(int num : oriStack) oriStack.pop_back();
        for(int num : minStack) minStack.pop_back();
    }
    
    void push(int x) {
        if(minStack.empty()) {
            minStack.push_back(x);
        }else {
            int top = minStack.back();
            if(x <= top) {
                minStack.push_back(x);
            }
        }
        oriStack.push_back(x);
    }
    
    void pop() {
        if(!minStack.empty() && oriStack.back() == minStack.back()) {
            minStack.pop_back();
        }
        oriStack.pop_back();
    }
    
    int top() {
        return oriStack.back();
    }
    
    int min() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */