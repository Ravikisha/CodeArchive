//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string roundToNearest(string str)
    {
        int n = str.size();
        int last_digit = str[n - 1] - '0';

        // If last digit is greater than or equal to 5, round up
        if (last_digit > 5)
        {
            // Set last digit to '0'
            str[n - 1] = '0';

            // Carry over the increment to the previous digit
            for (int i = n - 2; i >= 0; i--)
            {
                if (str[i] == '9')
                {
                    str[i] = '0'; // Set it to 0 and continue carrying
                }
                else
                {
                    str[i] = (char)((str[i] - '0') + 1 + '0');
                    return str;
                }
            }

            // If we carried all the way through (e.g., 999 -> 1000)
            str = '1' + str;
        }
        else
        {
            // If last digit is less than 5, round down by setting it to '0'
            str[n - 1] = '0';
        }

        return str;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends