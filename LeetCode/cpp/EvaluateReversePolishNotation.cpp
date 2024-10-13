class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> oprs;

        for (const string &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = oprs.top();
                oprs.pop();
                int a = oprs.top();
                oprs.pop();

                if (token == "+")
                    oprs.push(a + b);
                else if (token == "-")
                    oprs.push(a - b);
                else if (token == "*")
                    oprs.push(a * b);
                else if (token == "/")
                    oprs.push(a / b);
            }
            else
            {
                oprs.push(
                    stoi(token)); // Directly push the number onto the stack
            }
        }

        return oprs.top();
    }
};