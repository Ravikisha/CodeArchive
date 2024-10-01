//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // If the mid element is greater than the next element
            if (mid < high && arr[mid] > arr[mid + 1])
            {
                return mid + 1;
            }
            // If the mid element is smaller than the previous element
            if (mid > low && arr[mid - 1] > arr[mid])
            {
                return mid;
            }

            // Check if the low is greater than the mid element
            // If yes, then the pivot element is in the left half
            // Else, the pivot element is in the right half
            if (arr[low] > arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return 0;
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
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends

// Alternate Solution
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        int result = INT_MAX;
        int index = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[low] <= arr[high])
            {
                if (arr[low] < result)
                {
                    index = low;
                    result = arr[low];
                }
                break;
            }

            if (arr[low] <= arr[mid])
            {
                if (arr[low] < result)
                {
                    index = low;
                    result = arr[low];
                }
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                if (arr[mid] < result)
                {
                    index = mid;
                    result = arr[mid];
                }
            }
        }
        return index;
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
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends