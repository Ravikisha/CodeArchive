//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    static bool comp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second < p2.second)
            return true;
        else if(p1.second > p2.second)
            return false;
        else{
            if(p1.first > p2.first)
                return true;
            else
                return false;
        }
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // convert start and end array to pair of <start,end>
        vector<pair<int,int>> meets;
        for(int i = 0; i < n; i++){
            meets.push_back({start[i],end[i]});
        }
        // sort pairs with increasing order of end times
        sort(meets.begin(), meets.end(), comp);
        
        // to store number of meetings can be held
        int count = 1;
        pair<int,int> last = meets[0]; // to store last meet which is going to held till now
        
        for(int i = 1; i < n; i++){
            // if start time of current meet is greater than end time of last meeting then this meeting can be held
            if(meets[i].first > last.second){
                count++;
                last = meets[i];
            }
        }
        return count; // return answer
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends