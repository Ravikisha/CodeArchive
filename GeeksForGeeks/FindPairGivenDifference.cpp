//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    // Step-1 Sort the array
    sort(arr, arr + size);
 
    // Initialize positions of two elements
    int l = 0;
    int r = 1;
 
    // take absolute value of difference
    // this does not affect the pair as A-B=diff is same as
    // B-A= -diff
    n = abs(n);
 
    // Search for a pair
 
    // These loop running conditions are sufficient
    while (l <= r and r < size) {
        int diff = arr[r] - arr[l];
        if (diff == n
            and l != r) // we need distinct elements in pair
                        // so l!=r
        {
            return true;
        }
        else if (diff > n) // try to reduce the diff
            l++;
        else // Note if l==r then r will be advanced thus no
             // pair will be missed
            r++;
    }
    return false;
 
}