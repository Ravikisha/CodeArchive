//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    // Bottom-Up Approach (Tabulation)
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        if (n < 3)
            return 0; // A bitonic sequence must have at least 3 elements
        vector<int> dp1(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && 1 + dp1[j] > dp1[i])
                    dp1[i] = 1 + dp1[j];
            }
        }
        vector<int> dp2(n, 1);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[j] < nums[i] && 1 + dp2[j] > dp2[i])
                    dp2[i] = 1 + dp2[j];
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp1[i] > 1 && dp2[i] > 1)
            { // Ensure both increasing and decreasing parts exist
                result = max(result, dp1[i] + dp2[i] - 1);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends