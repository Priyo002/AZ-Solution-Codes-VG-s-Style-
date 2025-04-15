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
    int arrayLength;
    cin >> arrayLength;

    vector<int> arr(arrayLength);

    for (int i = 0; i < arrayLength; i++) cin >> arr[i];

    vector<int> increasingSubsequence, dp(arrayLength);

    // Calculate the length of the longest increasing subsequence ending at each index
    for (int i = 0; i < arrayLength; i++) {
        auto it = lower_bound(increasingSubsequence.begin(), increasingSubsequence.end(), arr[i]);
        if (it != increasingSubsequence.end()) *it = arr[i];
        else increasingSubsequence.push_back(arr[i]);

        dp[i] = increasingSubsequence.size();
    }

    increasingSubsequence.clear();
    int maxMountainLength = -1;

    // Calculate the length of the longest decreasing subsequence starting at each index
    for (int i = arrayLength - 1; i >= 0; i--) {
        auto it = lower_bound(increasingSubsequence.begin(), increasingSubsequence.end(), arr[i]);
        if (it != increasingSubsequence.end()) *it = arr[i];
        else increasingSubsequence.push_back(arr[i]);

        // Check if a valid mountain can be formed with the current peak
        if (increasingSubsequence.size() >= 2 && dp[i] >= 2) {
            maxMountainLength = max(maxMountainLength, dp[i] + ((int)increasingSubsequence.size()) - 1);
        }
    }

    if (maxMountainLength != -1) cout << arrayLength - maxMountainLength << endl;
    else cout << -1 << endl;
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