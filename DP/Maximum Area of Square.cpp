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

    vector<vector<int>> grid(numRows, vector<int>(numCols));
    int maxSquareSide = 0;

    // Read the grid
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> grid[i][j];
        }
    }

    // Dynamic programming to find the largest square of 1s
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] && i > 0 && j > 0) {
                grid[i][j] = 1 + min({grid[i][j - 1], grid[i - 1][j], grid[i - 1][j - 1]});
            }
            maxSquareSide = max(maxSquareSide, grid[i][j]);
        }
    }

    // The area of the largest square is the side squared
    cout << maxSquareSide * maxSquareSide << endl;
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