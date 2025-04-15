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

int numBricks, numColors, numDiffPositions;
int dp[2001][2001];

// Function to calculate the number of ways to color the bricks
int countWays(int index, int diffCount) {
    if (index == numBricks) return diffCount == numDiffPositions;
    if (dp[index][diffCount] != -1) return dp[index][diffCount];

    int ways = countWays(index + 1, diffCount);  // Continue with the same color
    ways %= mod;
    ways += (numColors - 1) * countWays(index + 1, diffCount + 1);  // Change color
    ways %= mod;

    return dp[index][diffCount] = ways;
}

void solve() {
    cin >> numBricks >> numColors >> numDiffPositions;
    memset(dp, -1, sizeof(dp));
    cout << (numColors * countWays(1, 0)) % mod << endl;  // Start with any color
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