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
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n);
    unordered_map<int, int> freq;
    
    // Read the numbers and count frequencies
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        freq[x[i]]++;
    }
    
    int score = 0;
    
    // Process each number in the frequency map
    for (auto& entry : freq) {
        int num = entry.first;
        int count = entry.second;
        
        if (num == k - num) {
            // Special case where a + a = k, we can form count // 2 pairs
            score += count / 2;
        } else if (num < k - num) {
            int other_count = freq[k - num];
            int pair_count = min(count, other_count);
            score += pair_count;
        }
    }
    
    cout << score << endl;
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
