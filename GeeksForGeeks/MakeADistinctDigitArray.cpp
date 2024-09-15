//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> common_digits(vector<int> nums)
    {
        set<int> oset;
        vector<int> v;
        for (int i : nums)
        {
            while (i > 0)
            {
                int rem = i % 10;
                i /= 10;
                if (oset.find(rem) == oset.end())
                    oset.insert(rem);
            }
        }
        for (int i : oset)
        {
            v.push_back(i);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        vector<int> ans = ob.common_digits(nums);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends