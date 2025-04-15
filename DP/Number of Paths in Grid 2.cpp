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

int grid[202][202];
int dp[202][202][402];
int numRows, numCols;

// Recursive function to calculate the number of paths
int countPaths(int row, int col, int remainingConversions) {
    if (row == numRows - 1 && col == numCols - 1) return 1;

    if (dp[row][col][remainingConversions] != -1) return dp[row][col][remainingConversions];

    int pathCount = 0;
    if (row + 1 < numRows) {
        if (grid[row + 1][col] == 1) {
            if (remainingConversions - 1 >= 0) {
                pathCount = (pathCount + countPaths(row + 1, col, remainingConversions - 1)) % mod;
            }
        } else {
            pathCount = (pathCount + countPaths(row + 1, col, remainingConversions)) % mod;
        }
    }
    if (col + 1 < numCols) {
        if (grid[row][col + 1] == 1) {
            if (remainingConversions - 1 >= 0) {
                pathCount = (pathCount + countPaths(row, col + 1, remainingConversions - 1)) % mod;
            }
        } else {
            pathCount = (pathCount + countPaths(row, col + 1, remainingConversions)) % mod;
        }
    }
    
    return dp[row][col][remainingConversions] = pathCount;
}

void solve() {
    int maxConversions;
    cin >> numRows >> numCols >> maxConversions;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == 1 && maxConversions == 0) {
        cout << 0 << endl;
        return;
    }

    // Initialize the dp array
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            for (int l = 0; l <= maxConversions; l++) {
                dp[i][j][l] = -1;
            }
        }
    }

    int totalPaths = countPaths(0, 0, maxConversions - (grid[0][0] == 1));

    cout << totalPaths << endl;
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