//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(sqrt(N))
    // Space Complexity: O(sqrt(N))
public:
    void print_divisors(int N)
    {
        vector<int> divisors;

        // Iterate from 1 to sqrt(N)
        for (int i = 1; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                divisors.push_back(i); // i is a divisor
                if (i != N / i)
                {
                    divisors.push_back(N / i);
                }
            }
        }

        // Sort divisors in ascending order
        sort(divisors.begin(), divisors.end());
        for (int i = 0; i < divisors.size(); i++)
            cout << divisors[i] << " ";
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends