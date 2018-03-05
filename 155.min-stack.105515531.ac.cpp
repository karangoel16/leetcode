/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (30.80%)
 * Total Accepted:    175K
 * Total Submissions: 568.2K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
class MinStack {
    stack<int> min;
    stack<int> min_val;
public:
    /** initialize your data structure here. */
    MinStack() {
        min.push(INT_MAX);
        min_val.push(INT_MAX);
    }
    
    void push(int x) {
        if(x<=min_val.top())
        {
            min_val.push(x);
        }
        min.push(x);
    }
    
    void pop() {
        int x=min.top();
        if(x==min_val.top())
        {
            min_val.pop();
        }
        min.pop();
    }
    
    int top() {
        return min.top();
        
    }
    
    int getMin() {
        return min_val.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
