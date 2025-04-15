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

int numElements;
int elements[501];
int dp[503][503];

// Function to calculate the minimum cost to merge elements from index l to r
int minMergeCost(int left, int right) {
    if (left == right) return 0;

    if (dp[left][right] != -1) return dp[left][right];

    int minCost = INF, prefixSum = 0, totalSum = 0;
    for (int mid = left; mid <= right; mid++) {
        totalSum += elements[mid];
    }
    for (int mid = left; mid < right; mid++) {
        prefixSum += elements[mid];
        minCost = min(minCost, minMergeCost(left, mid) + minMergeCost(mid + 1, right) + ((prefixSum % 100) * ((totalSum - prefixSum) % 100)));
    }

    return dp[left][right] = minCost;
}

void solve() {
    cin >> numElements;

    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << minMergeCost(0, numElements - 1) << endl;
}

int32_t main() {

    fastIO();

    int testCases = 1;
    //cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}