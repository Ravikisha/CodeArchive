class MyQueue
{
    // Space Complexity: O(n)
    // n is the number of elements in the queue
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    // Time Complexity: O(n)
    void push(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Time Complexity: O(1)
    int pop()
    {
        // if first stack is empty
        if (s1.empty())
        {
            return -1;
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }

    // Time Complexity: O(1)
    int peek()
    {
        return s1.top();
    }

    // Time Complexity: O(1)
    bool empty()
    {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */