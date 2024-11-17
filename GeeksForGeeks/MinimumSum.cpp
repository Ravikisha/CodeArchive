//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Time Complexity: O(n) where n is the length of the larger string
    // Space Complexity: O(1)
    string findSum(string str1, string str2)
    {
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length())
            swap(str1, str2);

        // Take an empty string for storing result
        string str = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();

        // Reverse both of strings
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int carry = 0;
        for (int i = 0; i < n1; i++)
        {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');

            // Calculate carry for next step
            carry = sum / 10;
        }

        // Add remaining digits of larger number
        for (int i = n1; i < n2; i++)
        {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining carry
        if (carry)
            str.push_back(carry + '0');

        // reverse resultant string
        reverse(str.begin(), str.end());

        return str;
    }

    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
    string minSum(vector<int> &arr)
    {
        string num1 = "", num2 = "";
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0)
            {
                num1 += to_string(arr[i]);
            }
            else
            {
                num2 += to_string(arr[i]);
            }
        }
        string str = findSum(num1, num2);
        while (str[0] == '0' && str.length() > 1)
        {
            str.erase(0, 1);
        }

        return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends