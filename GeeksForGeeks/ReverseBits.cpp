//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
  public:
    long long reversedBits(long long x) {
        ll out = 0;
    int n = 32;

    if (x & 1)
        out |= 1;

    for (int i=1; i<n; i++) {
        x >>= 1;
        out <<= 1;
        if (x & 1)
            out |= 1;
    }
    
    return out;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends