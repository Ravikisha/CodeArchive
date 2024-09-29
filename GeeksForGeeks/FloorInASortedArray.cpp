//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(logn)
    // Space Complexity: O(1) or O(logn) if we consider the recursive stack space
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    long long floorSearch(vector<long long> arr, long long low, long long high, long long x)
    {
        // If low and high cross each other
        if (low > high)
            return -1;

        // If last element is smaller than x
        if (x >= arr[high])
            return high;

        // Find the middle point
        int mid = (low + high) / 2;

        // If middle point is floor.
        if (arr[mid] == x)
            return mid;

        // If x lies between mid-1 and mid
        if (mid > 0 && arr[mid - 1] <= x && x < arr[mid])
            return mid - 1;

        // If x is smaller than mid, floor
        // must be in left half.
        if (x < arr[mid])
            return floorSearch(arr, low, mid - 1, x);

        // If mid-1 is not floor and x is
        // greater than arr[mid],
        return floorSearch(arr, mid + 1, high, x);
    }
    int findFloor(vector<long long> v, long long n, long long x)
    {
        return floorSearch(v, 0, n - 1, x);
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends



// Alternative Solution (Iteratively):


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    // Time Complexity: O(logn)
    // Space Complexity: O(1)
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {
        int high = n-1;
        int low = 0;
        int result = n;
        // if the target is smaller than the first element in array
        if(x < v[0]) return -1;
        // if the last element is smaller than target
        if(v[n-1] < x) return n-1;
        
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(v[mid] <= x && x < v[mid+1]){
                return mid;
            }else if(v[mid+1] <= x) low = mid+1;
            else if(v[mid] > x) high = mid-1;
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends
