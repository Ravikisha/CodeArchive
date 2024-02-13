//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int value(char r)
    {
        if (r == 'I')
            return 1;
        if (r == 'V')
            return 5;
        if (r == 'X')
            return 10;
        if (r == 'L')
            return 50;
        if (r == 'C')
            return 100;
        if (r == 'D')
            return 500;
        if (r == 'M')
            return 1000;

        return -1;
    }
    int romanToDecimal(string &str)
    {
        int result = 0;
        for (int i = 0; i < str.length(); i++)
        {
            int v1 = value(str[i]);

            if (i + 1 < str.length())
            {
                int v2 = value(str[i + 1]);

                if (v1 >= v2)
                {
                    result += v1;
                }
                else
                {
                    result = result + v2 - v1;
                    i++;
                }
            }
            else
            {
                result += v1;
            }
        }
        return result;
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
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends