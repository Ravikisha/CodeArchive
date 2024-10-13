class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> s;
        for (int x : asteroids)
            if (s.empty() || s.back() < 0 || x > 0)
                s.push_back(x);
            else
            {
                while (!s.empty() && s.back() > 0 && abs(x) > s.back())
                    s.pop_back();
                if (s.empty() || s.back() < 0)
                    s.push_back(x);
                else if (abs(x) == s.back())
                    s.pop_back();
            }
        return s;
    }
};

/*
Explaination:
1. If the stack is empty or the top element is negative or the current element is positive, we can directly push the current element to the stack.
2. If the current element is negative and the top element is positive, we need to check for collision.
3. If the current element is negative and the top element is negative, we can directly push the current element to the stack.
4. If the current element is equal to the top element, we can pop the top element from the stack.
5. After iterating through all the elements, the stack will contain the final result.
6. Return the stack as the result.

*/