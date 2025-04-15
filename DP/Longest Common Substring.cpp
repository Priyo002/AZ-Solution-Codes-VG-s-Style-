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

string str1, str2;
int len1, len2;
int dp[1001][1001];

// Function to find the length of the longest common substring
int longestCommonSubstring(int i, int j) {
    if (i == len1 || j == len2) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];

    int result = 0;
    if (str1[i] == str2[j]) {
        result = 1 + longestCommonSubstring(i + 1, j + 1);
    }
    // Explore other possibilities without storing results
    longestCommonSubstring(i + 1, j);
    longestCommonSubstring(i, j + 1);

    return dp[i][j] = result;
}

void solve() {
    cin >> str1 >> str2;
    len1 = str1.size();
    len2 = str2.size();
    
    memset(dp, -1, sizeof(dp));

    int maxLength = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            maxLength = max(maxLength, longestCommonSubstring(i, j));
        }
    }
    cout << maxLength << endl;
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