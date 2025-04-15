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

int dp[1001][1001];
string inputString;

// Function to find the minimum number of insertions to make the string a palindrome
int minInsertionsToPalindrome(int left, int right) {
    if (left >= right) return 0;  // Base case: single character or empty string

    if (dp[left][right] != -1) return dp[left][right];

    int minInsertions = INF;
    if (inputString[left] == inputString[right]) {
        minInsertions = minInsertionsToPalindrome(left + 1, right - 1);
    } else {
        minInsertions = min(minInsertions, 1 + minInsertionsToPalindrome(left + 1, right));
        minInsertions = min(minInsertions, 1 + minInsertionsToPalindrome(left, right - 1));
    }
    return dp[left][right] = minInsertions;
}

void solve() {
    cin >> inputString;
    int length = inputString.size();
    memset(dp, -1, sizeof(dp));
    cout << minInsertionsToPalindrome(0, length - 1) << endl;
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