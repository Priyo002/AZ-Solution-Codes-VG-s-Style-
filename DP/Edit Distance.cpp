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

int dp[501][501];
string word1, word2;
int len1, len2;

// Function to calculate the minimum number of operations to convert word1 to word2
int minOperations(int i, int j) {
    if (i == len1) return len2 - j;  // Insert remaining characters of word2
    if (j == len2) return len1 - i;  // Delete remaining characters of word1

    if (dp[i][j] != -1) return dp[i][j];

    int result = INF;
    if (word1[i] == word2[j]) {
        result = min(result, minOperations(i + 1, j + 1));  // Characters match, move to next
    } else {
        result = min(result, 1 + minOperations(i + 1, j + 1));  // Replace character
        result = min(result, 1 + minOperations(i + 1, j));      // Delete character
        result = min(result, 1 + minOperations(i, j + 1));      // Insert character
    }
    return dp[i][j] = result;
}

void solve() {
    cin >> word1 >> word2;
    len1 = word1.size();
    len2 = word2.size();
    memset(dp, -1, sizeof(dp));
    cout << minOperations(0, 0) << endl;
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