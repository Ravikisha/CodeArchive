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

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// } Driver Code Ends
// User function template for C++

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<vector<int>> getPairs(vector<int> &arr)
    {
        unordered_set<int> seen;
        unordered_set<int> added;
        vector<vector<int>> result;

        // Iterate through the array
        for (int num : arr)
        {
            if (seen.count(-num) && !added.count(abs(num)))
            {
                result.push_back({min(num, -num), max(num, -num)});
                added.insert(abs(num)); // To avoid duplicate pairs
            }
            seen.insert(num);
        }

        // Sorting the result to meet the required output order
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.
// Back-end complete function Template for C++

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int n = arr.size();
        // char c;cin>>c;
        Solution obj;
        vector<vector<int>> res = obj.getPairs(arr);
        if (res.size() == 0)
        {
            cout << endl;
        }
        else
            Matrix::print(res);
        cout << "~" << endl;
    }
}

// } Driver Code Ends