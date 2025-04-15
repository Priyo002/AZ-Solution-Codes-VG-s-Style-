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

int numLength;
string forbidden = "0100";
int dp[1001000][5];

// Function to count binary strings of length 'level' without "0100" as a substring
int countValidStrings(int level, int match) {
    if (match == 4) return 0;  // If "0100" is formed, return 0
    if (level == 0) return 1;  // If no more characters to add, return 1

    if (dp[level][match] != -1) return dp[level][match];

    int count = 0;
    if (match == 0) {
        count += countValidStrings(level - 1, 1);  // Add '0'
        count += countValidStrings(level - 1, 0);  // Add '1'
    } else if (match == 1) {
        count += countValidStrings(level - 1, 1);  // Add '0'
        count += countValidStrings(level - 1, 2);  // Add '1'
    } else if (match == 2) {
        count += countValidStrings(level - 1, 3);  // Add '0'
        count += countValidStrings(level - 1, 0);  // Add '1'
    } else if (match == 3) {
        count += countValidStrings(level - 1, 4);  // Add '0'
        count += countValidStrings(level - 1, 2);  // Add '1'
    }

    return dp[level][match] = (count % mod);
}

void solve() {
    cin >> numLength;
    cout << countValidStrings(numLength, 0) << endl;
}

int32_t main() {

    fastIO();

    int testCases = 1;
    cin >> testCases;
    memset(dp, -1, sizeof(dp));
    while (testCases--) {
        solve();
    }

    return 0;
}