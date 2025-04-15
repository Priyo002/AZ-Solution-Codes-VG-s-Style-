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

int dp[5001][5001];

// Function to calculate the number of ways to partition n into k parts
int countPartitions(int n, int k) {
    if (n == 0) return 1;  // Base case: exactly partitioned
    if (n < 0 || k <= 0) return 0;  // Invalid partition
    if (dp[n][k] != -1) return dp[n][k];

    int ways = countPartitions(n, k - 1);  // Exclude current k
    ways %= mod;
    ways += countPartitions(n - k, k);  // Include current k
    ways %= mod;
    return dp[n][k] = ways;
}

void solve() {
    int n, k;
    cin >> n >> k;

    n -= k;  // Adjust n to account for each part being at least 1
    cout << (countPartitions(n, k) % mod) << endl;
}

int32_t main() {

    fastIO();

    memset(dp, -1, sizeof(dp));  // Initialize dp array with -1
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}