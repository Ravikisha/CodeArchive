//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
		int index1 = -1, index2 = -1;
        int minCnt = INT_MAX;
    
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == word1) {
                index1 = i;
            } else if (s[i] == word2) {
                index2 = i;
            }
    
            // Calculate distance if both words have been found at least once
            if (index1 != -1 && index2 != -1) {
                minCnt = min(minCnt, abs(index1 - index2));
            }
        }
        
        return minCnt == INT_MAX ? 0 : minCnt;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends