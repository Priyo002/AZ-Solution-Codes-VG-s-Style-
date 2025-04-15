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

int numMarbles;
int colors[1001];
int dp[101][101][101];
vector<vector<int>> occurrences;

// Function to calculate the maximum points
int maxPoints(int left, int right, int count) {
    if (left > right) return 0;

    if (dp[left][right][count] != -1) return dp[left][right][count];

    // Remove the first group of marbles and calculate points
    int maxScore = maxPoints(left + 1, right, 0) + ((count + 1) * (count + 1));

    // Try to merge with the same color marbles further in the array
    for (int mid = left + 1; mid <= right; mid++) {
        if (colors[left] == colors[mid]) {
            maxScore = max(maxScore, maxPoints(left + 1, mid - 1, 0) + maxPoints(mid, right, count + 1));
            break;
        }
    }
    
    return dp[left][right][count] = maxScore;
}

void solve() {
    cin >> numMarbles;

    occurrences.clear();
    occurrences.resize(1001, vector<int>());

    for (int i = 0; i < numMarbles; i++) {
        cin >> colors[i];
        occurrences[colors[i]].push_back(i);
    }
    memset(dp, -1, sizeof(dp));
    cout << maxPoints(0, numMarbles - 1, 0) << endl;
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