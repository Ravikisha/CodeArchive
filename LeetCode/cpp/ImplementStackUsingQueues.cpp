class MyStack
{
    // Space Complexity: O(n)
public:
    queue<int> q1, q2;
    MyStack()
    {
    }

    // Time Complexity: O(1)
    void push(int x)
    {
        q1.push(x);
    }

    // Time Complexity: O(n)
    int pop()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        // last element in q1
        int x = q1.front();
        q1.pop();
        q1.swap(q2);
        return x;
    }

    // Time Complexity: O(1)
    int top()
    {
        return q1.back();
    }

    // Time Complexity: O(1)
    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */