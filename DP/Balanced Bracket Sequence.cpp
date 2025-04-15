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

int sequenceLength;
string bracketSequence;
int dp[1010][1010];

// Function to calculate the number of ways to form a balanced bracket sequence
int countWays(int position, int openBrackets) {
    if (openBrackets < 0) return 0;  // More closing brackets than opening

    if (position == sequenceLength) return (openBrackets == 0);  // Valid if all brackets are closed

    if (dp[position][openBrackets] != -1) return dp[position][openBrackets];

    int ways = 0;
    if (bracketSequence[position] == '(') {
        ways += countWays(position + 1, openBrackets + 1);
        ways %= mod;
    } else if (bracketSequence[position] == ')') {
        ways += countWays(position + 1, openBrackets - 1);
        ways %= mod;
    } else {  // '?'
        ways += countWays(position + 1, openBrackets + 1);  // Treat '?' as '('
        ways %= mod;
        ways += countWays(position + 1, openBrackets - 1);  // Treat '?' as ')'
        ways %= mod;
    }

    return dp[position][openBrackets] = ways;
}

void solve() {
    cin >> bracketSequence;
    sequenceLength = bracketSequence.size();

    // Initialize dp array
    for (int i = 0; i <= sequenceLength; i++) {
        for (int j = 0; j <= sequenceLength; j++) {
            dp[i][j] = -1;
        }
    }
    
    cout << countWays(0, 0) << endl;
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