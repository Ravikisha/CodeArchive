//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        if (n == 0)
            return 0;
        int previous = a[0];
        int lastIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == previous)
                continue;
            a[lastIndex + 1] = a[i];
            previous = a[i];
            lastIndex++;
        }
        return lastIndex + 1;
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
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        int n = ob.remove_duplicate(a, N);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends