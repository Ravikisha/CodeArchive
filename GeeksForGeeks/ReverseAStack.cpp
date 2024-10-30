//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
public:
    // Helper function to insert element at the bottom of the stack
    void insertAtBottom(stack<int> &St, int value)
    {
        if (St.empty())
        {
            St.push(value);
            return;
        }
        int topElement = St.top();
        St.pop();
        insertAtBottom(St, value); // Recursively reach the bottom
        St.push(topElement);       // Restore the elements back after insertion
    }

    // Function to reverse the stack using recursion
    void Reverse(stack<int> &St)
    {
        if (St.empty())
            return;
        int value = St.top();
        St.pop();
        Reverse(St);               // Recursively reverse the remaining stack
        insertAtBottom(St, value); // Insert each popped element at the bottom
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int> res;
        while (St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }

        cout << endl;

        cout << "~" << "\n";
    }
}
// } Driver Code Ends