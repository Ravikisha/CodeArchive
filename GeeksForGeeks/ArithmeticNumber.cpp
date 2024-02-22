//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int inSequence(int A, int B, int C)
    {
        if (C == 0)
        {
            if (A == B)
            {
                return 1; // B is equal to A
            }
            else
            {
                return 0; // B cannot be present if common difference is 0
            }
        }
        if ((B - A) % C == 0 && ((B - A >= 0 && C > 0) || (B - A <= 0 && C < 0)))
        {
            return 1; // B is present in the arithmetic sequence
        }
        else
        {
            return 0; // B is not present in the arithmetic sequence
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        Solution ob;
        cout << ob.inSequence(A, B, C) << endl;
    }
    return 0;
}
// } Driver Code Endss