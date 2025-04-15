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
    int numRows, numCols;
    cin >> numRows >> numCols;

    vector<vector<int>> dungeon(numRows, vector<int>(numCols));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> dungeon[i][j];
        }
    }

    vector<vector<int>> minHealth(numRows, vector<int>(numCols));

    // Calculate minimum health needed at the exit
    if (dungeon[numRows - 1][numCols - 1] <= 0) {
        minHealth[numRows - 1][numCols - 1] = abs(dungeon[numRows - 1][numCols - 1]) + 1;
    } else {
        minHealth[numRows - 1][numCols - 1] = 1;
    }

    // Fill the DP table from bottom-right to top-left
    for (int i = numRows - 1; i >= 0; i--) {
        for (int j = numCols - 1; j >= 0; j--) {
            if (i == numRows - 1 && j == numCols - 1) continue;
            minHealth[i][j] = INF;
            if (j + 1 < numCols) {
                minHealth[i][j] = min(minHealth[i][j], max(1LL, minHealth[i][j + 1] - dungeon[i][j]));
            }
            if (i + 1 < numRows) {
                minHealth[i][j] = min(minHealth[i][j], max(1LL, minHealth[i + 1][j] - dungeon[i][j]));
            }
        }
    }
    cout << minHealth[0][0] << endl;
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