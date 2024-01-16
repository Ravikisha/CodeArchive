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

void solve() {
    int count = 0;
    for (int i=0;i<4;i++){
        int a;
        cin >> a;
        if (a >= 10){
            count++;
        }
    }
    cout << count;
}

int main() {
    fastio;
    solve();

    return 0;
}
