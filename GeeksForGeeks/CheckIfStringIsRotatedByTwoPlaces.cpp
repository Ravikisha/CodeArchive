//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if (str1.size() != str2.size() || (str1.size() < 2 && str2.size() < 2))
            return 0;
        string clockwise = "";
        string anticlockwise = "";
        int l = str2.length();
        clockwise = clockwise + str2.substr(2, l - 2) + str2.substr(0, 2);
        anticlockwise = anticlockwise + str2.substr(l - 2, 2) + str2.substr(0, l - 2);
        if (str1 == clockwise || str1 == anticlockwise)
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
        string s;
        string b;
        cin >> s >> b;
        Solution obj;
        cout << obj.isRotated(s, b) << endl;
    }
    return 0;
}

// } Driver Code Ends