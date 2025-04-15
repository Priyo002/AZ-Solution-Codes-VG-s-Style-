#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const long long INF = 1e18;

// Enable fast I/O
void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int numGems;
int gemstones[110];
int dp[110][110];

// Function to find the minimum number of seconds to destroy all gemstones
int minSecondsToDestroy(int left, int right) {
    if (left > right) return 0;

    if (dp[left][right] != -1) return dp[left][right];

    // Remove the first gemstone and solve for the rest
    int minSeconds = 1 + minSecondsToDestroy(left + 1, right);

    // Check if the first two gemstones are the same
    if (left + 1 <= right && gemstones[left] == gemstones[left + 1]) {
        minSeconds = min(minSeconds, 1 + minSecondsToDestroy(left + 2, right));
    }

    // Check for palindromic substrings starting and ending with the same gemstone
    for (int j = left + 2; j <= right; j++) {
        if (gemstones[left] == gemstones[j]) {
            minSeconds = min(minSeconds, minSecondsToDestroy(left + 1, j - 1) + minSecondsToDestroy(j + 1, right));
        }
    }

    return dp[left][right] = minSeconds;
}

void solve() {
    cin >> numGems;
    for (int i = 0; i < numGems; i++) {
        cin >> gemstones[i];
    }
    memset(dp, -1, sizeof(dp));

    cout << minSecondsToDestroy(0, numGems - 1) << endl;
}

int32_t main() {

    fastIO();

    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}