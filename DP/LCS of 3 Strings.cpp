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

string str1, str2, str3;
int dp[101][101][101];

// Recursive function to find the longest common subsequence
int longestCommonSubsequence(int i, int j, int k) {
    if (i == str1.size() || j == str2.size() || k == str3.size()) {
        return 0;
    }
    if (dp[i][j][k] != -1) return dp[i][j][k];

    int result = 0;
    if (str1[i] == str2[j] && str2[j] == str3[k]) {
        result = 1 + longestCommonSubsequence(i + 1, j + 1, k + 1);
    } else {
        result = max({longestCommonSubsequence(i + 1, j, k),
                      longestCommonSubsequence(i, j + 1, k),
                      longestCommonSubsequence(i, j, k + 1)});
    }
    return dp[i][j][k] = result;
}

void solve() {
    cin >> str1 >> str2 >> str3;

    memset(dp, -1, sizeof(dp));
    cout << longestCommonSubsequence(0, 0, 0) << endl;
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