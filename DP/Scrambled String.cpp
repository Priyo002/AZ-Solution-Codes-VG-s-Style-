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
int dp[50][50][50];

// Function to check if str2 is a scrambled version of str1
int isScramble(int i, int j, int l, int r) {
    if (i > j || l > r) return 0;
    if (i == j) return str1[i] == str2[l];
    if (str1.substr(i, j - i + 1) == str2.substr(l, r - l + 1)) return 1;

    if (dp[i][j][l] != -1) return dp[i][j][l];

    int isScrambled = 0;
    for (int k = i; k < j; k++) {
        // Check both possible scrambled combinations
        int option1 = isScramble(i, k, l, l + (k - i)) && isScramble(k + 1, j, l + (k - i) + 1, r);
        int option2 = isScramble(i, k, r - (k - i), r) && isScramble(k + 1, j, l, l + (j - k - 1));

        isScrambled |= (option1 | option2);
    }

    return dp[i][j][l] = isScrambled;
}

void solve() {
    cin >> str1 >> str2;

    int len1 = str1.size(), len2 = str2.size();
    memset(dp, -1, sizeof(dp));
    
    cout << (isScramble(0, len1 - 1, 0, len2 - 1) ? "Yes" : "No") << endl;
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