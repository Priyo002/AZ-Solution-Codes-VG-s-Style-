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

int numRows, numCols, divisor;
int board[101][101];
int dp[101][101][12];

// Function to calculate the maximum score divisible by K
int calculateMaxScore(int row, int col, int score) {
    if (row == 0) {
        // Check if the score is divisible by K
        if ((score + board[row][col]) % divisor == 0) return board[row][col];
        else return -1e9;
    }
    if (dp[row][col][score] != -1) return dp[row][col][score];

    int currentMaxScore = -1e9;
    // Move upwards and left
    if (col - 1 >= 0) {
        currentMaxScore = max(currentMaxScore, calculateMaxScore(row - 1, col - 1, (score + board[row][col]) % divisor));
    }
    // Move upwards and right
    if (col + 1 < numCols) {
        currentMaxScore = max(currentMaxScore, calculateMaxScore(row - 1, col + 1, (score + board[row][col]) % divisor));
    }

    if (currentMaxScore != -1e9) currentMaxScore += board[row][col];

    return dp[row][col][score] = currentMaxScore;
}

void solve() {
    cin >> numRows >> numCols >> divisor;

    for (int i = 0; i < numRows; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < numCols; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));

    int maxOverallScore = -1e9;
    // Start from any cell in the bottom row
    for (int j = 0; j < numCols; j++) {
        maxOverallScore = max(maxOverallScore, calculateMaxScore(numRows - 1, j, 0));
    }

    if (maxOverallScore != -1e9) cout << maxOverallScore;
    else cout << -1;
    cout << endl;
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