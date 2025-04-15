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

int numChars;
string inputString, target = "hard";
int removalCost[100100];
int dp[101001][5];

// Function to find the minimum cost to remove characters to avoid "hard" subsequence
int minCostToAvoidHard(int index, int matchIndex) {
    if (matchIndex == 4) return INF;  // If "hard" is formed, return a large cost

    if (index == numChars) return 0;  // If end of string is reached, no cost

    if (dp[index][matchIndex] != -1) return dp[index][matchIndex];

    int cost = INF;
    
    if (inputString[index] == target[matchIndex]) {
        // Option 1: Don't delete the character, move to the next match
        cost = min(cost, minCostToAvoidHard(index + 1, matchIndex + 1));
        // Option 2: Delete the character, add its cost
        cost = min(cost, removalCost[index] + minCostToAvoidHard(index + 1, matchIndex));
    } else {
        // If character doesn't match, just move to the next character
        cost = minCostToAvoidHard(index + 1, matchIndex);
    }

    return dp[index][matchIndex] = cost;
}

void solve() {
    cin >> numChars;
    cin >> inputString;
    for (int i = 0; i < numChars; i++) cin >> removalCost[i];
    memset(dp, -1, sizeof(dp));
    cout << minCostToAvoidHard(0, 0) << endl;
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