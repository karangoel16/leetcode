/*
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (37.95%)
 * Total Accepted:    101.9K
 * Total Submissions: 268.4K
 * Testcase Example:  '["MyQueue","empty"]\n[[],[]]'
 *
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * 
 * peek() -- Get the front element.
 * 
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 * 
 * 
 */
void support(stack<int> & stack1,stack <int> &stack2)
{
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
}
class Queue {
    stack<int> stack1;
    stack<int> stack2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);//this is to push the element ibto the node
    }

    // Removes the element from in front of queue.
    void pop(void) {
        support(stack1,stack2);
        stack2.pop();//this is done to pop out the first element
    }

    // Get the front element.
    int peek(void) {
        support(stack1,stack2);
        return stack2.top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        if(stack1.empty() && stack2.empty())
        {
            return true;
        }
        return false;
    }
};
