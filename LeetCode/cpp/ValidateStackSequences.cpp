class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int n1 = pushed.size();
        int n2 = popped.size();
        if (n1 != n2)
            return false;
        int i = 0, j = 0;

        while (i < n1)
        {
            st.push(pushed[i]);
            i++;
            // Keep popping while the top of the stack matches the current element in popped
            while (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }

        // In the end, the stack should be empty if the sequences are valid
        return st.empty();
    }
};