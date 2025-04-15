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

int numStrings;
vector<string> originalStrings, reversedStrings;
vector<int> reversalCost;
int dp[100100][2];

// Function to calculate the minimum cost to sort strings lexicographically
int minCostToSort(int index, int isReversed) {
    if (index == numStrings) return 0;

    if (dp[index][isReversed] != -1) return dp[index][isReversed];

    int minCost = INF;
    if (isReversed && reversedStrings[index - 1] <= originalStrings[index]) {
        minCost = min(minCost, minCostToSort(index + 1, 0));
    }
    if (isReversed && reversedStrings[index - 1] <= reversedStrings[index]) {
        minCost = min(minCost, reversalCost[index] + minCostToSort(index + 1, 1));
    }
    if (!isReversed && originalStrings[index - 1] <= originalStrings[index]) {
        minCost = min(minCost, minCostToSort(index + 1, 0));
    }
    if (!isReversed && originalStrings[index - 1] <= reversedStrings[index]) {
        minCost = min(minCost, reversalCost[index] + minCostToSort(index + 1, 1));
    }

    return dp[index][isReversed] = minCost;
}

void solve() {
    cin >> numStrings;

    originalStrings.clear();
    reversedStrings.clear();
    reversalCost.clear();

    reversalCost.resize(numStrings);
    originalStrings.resize(numStrings);
    reversedStrings.resize(numStrings);

    for (int i = 0; i < numStrings; i++) {
        cin >> reversalCost[i];
    }

    for (int i = 0; i < numStrings; i++) {
        string s;
        cin >> s;
        originalStrings[i] = s;
        reverse(s.begin(), s.end());
        reversedStrings[i] = s;
    }

    memset(dp, -1, sizeof(dp));

    int costWithoutFirstReversal = minCostToSort(1, 0);
    int costWithFirstReversal = reversalCost[0] + minCostToSort(1, 1);

    int minTotalCost = min(costWithoutFirstReversal, costWithFirstReversal);

    if (minTotalCost == INF) cout << -1;
    else cout << minTotalCost;
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