class Solution
{
    // Time Complexity: O(4^n/sqrt(n))
    // Space Complexity: O(4^n/sqrt(n))
public:
    void helper(vector<string> &res, string str, int l, int r)
    {
        if (l > r)
            return;
        if (!l && !r)
        {
            res.push_back(str);
            return;
        }
        if (l > 0)
        {
            helper(res, str + '(', l - 1, r);
        }
        if (r > 0)
        {
            helper(res, str + ')', l, r - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(res, string() = "", n, n);
        return res;
    }
};

// Stack Based Code for the same problem (Using ChatGPT)
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        stack<tuple<string, int, int>> stk; // Stack to hold (current string, left remaining, right remaining)

        // Initialize stack with the initial state
        stk.push(make_tuple("", n, n));

        // Iterate until stack is empty
        while (!stk.empty())
        {
            auto [str, l, r] = stk.top(); // Get the top element (current string, l, r)
            stk.pop();                    // Pop the top element

            // If no more parentheses can be added, add the result to the list
            if (l == 0 && r == 0)
            {
                res.push_back(str);
                continue;
            }

            // If there are remaining right parentheses, add ')' to the string and push new state
            if (r > 0 && l <= r)
            {
                stk.push(make_tuple(str + ')', l, r - 1));
            }

            // If there are remaining left parentheses, add '(' to the string and push new state
            if (l > 0)
            {
                stk.push(make_tuple(str + '(', l - 1, r));
            }
        }

        return res;
    }
};
