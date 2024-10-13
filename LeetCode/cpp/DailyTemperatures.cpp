class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> st;

        int n = temperatures.size();

        vector<int> ans(n, 0);

        for (int i = n - 1; i > -1; i--)
        {
            while (st.size() and st.top().first <= temperatures[i])
                st.pop();

            if (st.size() and st.top().first > temperatures[i])
                ans[i] = st.top().second - i;

            st.push({temperatures[i], i});
        }

        return ans;
    }
};

/*
Explanation:
1. We use a stack to store the temperatures and their indices.
2. We iterate through the temperatures in reverse order.
3. If the stack is not empty and the top element is less than or equal to the current temperature, we pop the top element.
4. If the stack is not empty and the top element is greater than the current temperature, we calculate the difference in indices and store it in the answer array.
5. We push the current temperature and its index to the stack.
6. After iterating through all the temperatures, the answer array will contain the number of days until the next warmer temperature.
7. Return the answer array.
Example:
Input: temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
Output: [1, 1, 4, 2, 1, 1, 0, 0]

Iterating through the temperatures in reverse order:
1. For temperature 73, the next warmer temperature is 76 after 1 day.
2. For temperature 76, there is no warmer temperature.
3. For temperature 72, the next warmer temperature is 76 after 1 day.
4. For temperature 69, the next warmer temperature is 71 after 2 days.
5. For temperature 71, the next warmer temperature is 75 after 4 days.
6. For temperature 75, the next warmer temperature is 76 after 1 day.
7. For temperature 74, the next warmer temperature is 75 after 1 day.
8. For temperature 73, there is no warmer temperature.

Output: [1, 1, 4, 2, 1, 1, 0, 0]
*/