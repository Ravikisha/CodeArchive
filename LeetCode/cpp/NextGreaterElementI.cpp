class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> stk;
        unordered_map<int, int> m;
        for (int &v : nums2)
        {
            while (!stk.empty() && stk.top() < v)
            {
                m[stk.top()] = v;
                stk.pop();
            }
            stk.push(v);
        }
        vector<int> ans;
        for (int &v : nums1)
            ans.push_back(m.count(v) ? m[v] : -1);
        return ans;
    }
};

/*
Explaination:
1. Create a stack and a map.
2. Iterate over nums2.
3. If the top of the stack is less than the current element, then pop the top element and add the current element to the map with the popped element as the key.
4. Push the current element to the stack.
5. Iterate over nums1 and add the value from the map to the answer vector.
6. Return the answer vector.

Example:
nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2]
stack = [], map = {}
Iterate num2
i = 0, v = 1
    stack = [1], map = {}
i = 1, v = 3
    map = {1: 3}, stack = [3]
i = 2, v = 4
    map = {1: 3, 3: 4}, stack = [4]
i = 3, v = 2
    map = {1: 3, 3: 4}, stack = [4, 2]

Iterate num1:
i = 0, v = 4
    map.count(4) = 0, ans = [-1]
i = 1, v = 1
    map.count(1) = 3, ans = [-1, 3]
i = 2, v = 2
    map.count(2) = 0, ans = [-1, 3, -1]
*/