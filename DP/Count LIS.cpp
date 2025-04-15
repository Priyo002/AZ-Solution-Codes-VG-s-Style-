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

void solve() {
    int numElements;
    cin >> numElements;

    vector<int> arr(numElements);
    for (int i = 0; i < numElements; i++) {
        cin >> arr[i];
    }

    vector<int> dp(numElements), count(numElements);
    int longestLength = 1;

    // Calculate the length of the longest increasing subsequence and count them
    for (int i = 0; i < numElements; i++) {
        count[i] = 1;
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    dp[i] %= mod;
                    count[i] = count[j];
                } else if (dp[i] == dp[j] + 1) {
                    count[i] += count[j];
                    count[i] %= mod;
                }
            }
            longestLength = max(longestLength, dp[i]);
        }
    }

    int totalCount = 0;
    for (int i = 0; i < numElements; i++) {
        if (dp[i] == longestLength) {
            totalCount += count[i];
            totalCount %= mod;
        }
    }

    cout << totalCount << endl;
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