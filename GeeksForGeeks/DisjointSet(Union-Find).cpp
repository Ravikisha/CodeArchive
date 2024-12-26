//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int find(int a[], int x);
void unionSet(int a[], int x, int z);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            if (s == "UNION")
            {
                int z, x;
                cin >> x >> z;
                unionSet(a, x, z);
            }
            else
            {
                int x;
                cin >> x;
                int parent = find(a, x);
                cout << parent << " ";
            }
        }
        cout << endl;

        cout << "~" << "\n";
    }
}
// } Driver Code Ends

/*Complete the functions below*/

// Time Complexity: O(log(n))
// Space Complexity: O(1)
int find(int A[], int X)
{
    if (A[X] != X)
    {
        // Path Compression
        A[X] = find(A, A[X]);
    }
    return A[X];
}

// Time Complexity: O(log(n))
// Space Complexity: O(1)
void unionSet(int A[], int X, int Z)
{
    // Find the ultimate parents of X and Z
    int parentX = find(A, X);
    int parentZ = find(A, Z);

    // Union by changing the parent of one to the other
    if (parentX != parentZ)
    {
        A[parentX] = parentZ; // Making parent of X point to parent of Z
    }
}