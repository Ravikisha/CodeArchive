#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;

// TODOLIST
void solve() {
    int a, count =0;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int n;
        cin >> n;
        if (n >= 1000){
            count++;
        }
    }
    cout << count << "\n";
    
}

int main() {
    fastio;

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
