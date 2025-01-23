//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int countPairs(vector<int> &arr, int target)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        int count = 0;

        while (left < right)
        {
            int sum = arr[left] + arr[right];

            if (sum == target)
            {
                if (arr[left] == arr[right])
                {
                    // Special case: All elements between left and right are the same
                    int numElements = right - left + 1;
                    count += (numElements * (numElements - 1)) / 2; // Combination formula
                    break;
                }
                // Count pairs with the same values
                int leftCount = 1, rightCount = 1;

                // Count duplicates for the left pointer
                while (left + 1 < right && arr[left] == arr[left + 1])
                {
                    leftCount++;
                    left++;
                }

                // Count duplicates for the right pointer
                while (right - 1 > left && arr[right] == arr[right - 1])
                {
                    rightCount++;
                    right--;
                }

                // Add combinations of pairs (leftCount * rightCount)
                count += leftCount * rightCount;

                // Move pointers inward
                left++;
                right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return count;
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends