class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st;
        for (int i = 0; i < operations.size(); i++)
        {
            if (!st.empty() && operations[i] == "+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            }
            else if (!st.empty() && operations[i] == "D")
            {
                int a = st.top();
                st.push(2 * a);
            }
            else if (!st.empty() && operations[i] == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(operations[i]));
            }
        }
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

// Better Code Formatting
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // We Don't need sum at the end, we can calculate in the loop
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> stack;
        int sum = 0;

        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i] == "+")
            {
                int first = stack.top();
                stack.pop();

                int second = stack.top();

                stack.push(first);

                stack.push(first + second);

                sum += first + second;
            }

            else if (ops[i] == "D")
            {
                sum += 2 * stack.top();
                stack.push(2 * stack.top());
            }

            else if (ops[i] == "C")
            {
                sum -= stack.top();
                stack.pop();
            }

            else
            {
                sum += stoi(ops[i]);
                stack.push(stoi(ops[i]));
            }
        }

        return sum;
    }
};