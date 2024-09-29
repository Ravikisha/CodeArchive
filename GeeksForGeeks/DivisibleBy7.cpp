//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    // Time Complexity: O(n) where n is the length of the string
    // Space Complexity: O(1)
  public:
    int isdivisible7(string num){
        int remainder = 0;
        for (int i = 0; i < num.length(); i++) {
            int digit = remainder * 10 + (num[i] - '0');
            remainder = digit % 7;
        }
        return remainder == 0 ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isdivisible7(s) << endl;
    }
    return 0;
}
// } Driver Code Ends