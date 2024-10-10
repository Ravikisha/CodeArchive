class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int maxWidthRamp(vector<int> &nums)
    {
        stack<int> st;
        int maxRamp = 0;
        st.push(0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[st.top()] > nums[i])
                st.push(i);
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                if (maxRamp < i - st.top())
                    maxRamp = i - st.top();
                st.pop();
            }
        }
        return maxRamp;
    }
};

/*
Explaination:
1. We will use stack to store the index of the elements in the array.
2. We will iterate the array from left to right and push the index of the elements in the stack.
3. If the element at the top of the stack is greater than the current element, we will push the current element in the stack.
4. We will iterate the array from right to left and pop the elements from the stack until the element at the top of the stack is less than the current element.
5. We will calculate the difference between the current index and the index at the top of the stack and update the maximum ramp.
6. We will return the maximum ramp.

*/