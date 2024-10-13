class MinStack
{
    // Space Complexity: O(n)
public:
    stack<int> st;
    stack<int> minStack;
    MinStack()
    {
    }

    // Time Complexity: O(1)
    void push(int val)
    {
        st.push(val);
        if (minStack.empty())
        {
            minStack.push(val);
        }
        else
        {
            if (minStack.top() > val)
            {
                minStack.push(val);
            }
            else
            {
                minStack.push(minStack.top());
            }
        }
    }

    // Time Complexity: O(1)
    void pop()
    {
        st.pop();
        minStack.pop();
    }

    // Time Complexity: O(1)
    int top()
    {
        return st.top();
    }

    // Time Complexity: O(1)
    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// More Reliable Solution
class MinStack
{
public:
    stack<int> st;
    stack<int> minStack;

    MinStack() {}

    void push(int val)
    {
        st.push(val);
        // Only push the value to minStack if it's smaller or equal to the
        // current minimum.
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        // If the top value of st is also the top value of minStack, pop it from
        // minStack as well.
        if (st.top() == minStack.top())
        {
            minStack.pop();
        }
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minStack.top(); }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */