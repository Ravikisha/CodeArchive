//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool checkPalin(int n)
    {
        int temp = n;
        int rev = 0;
        while(temp > 0)
        {
            rev = rev*10 + temp%10;
            temp = temp/10;
        }
        if(rev == n)
            return true;
        else
            return false;
    }

    int PalinArray(int a[], int n)
    {
        //add code here.
        for(int i = 0; i < n; i++)
        {
            if(!checkPalin(a[i]))
                return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends