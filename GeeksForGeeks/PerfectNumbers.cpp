//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isPerfectNumber(long long N)
    {
        long long int sum = 1;

        // Find all divisors and add them
        for (long long int i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                if (i * i != N)
                    sum = sum + i + N / i;
                else
                    sum = sum + i;
            }
        }
        // If sum of divisors is equal to
        // n, then n is a perfect number
        if (sum == N && N != 1)
            return 1;

        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;

        cin >> N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends