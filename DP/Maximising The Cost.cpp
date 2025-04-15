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

string inputString;
int dp[101][101][30];
vector<vector<int>> costMatrix;

// Function to calculate the maximum cost with at most 'k' changes
int maxCost(int index, int remainingChanges, int prevChar) {
    if (index == (int)inputString.size()) return 0;

    if (dp[index][remainingChanges][prevChar] != -1) return dp[index][remainingChanges][prevChar];

    int maxCostValue = costMatrix[prevChar][inputString[index] - 'a'] + maxCost(index + 1, remainingChanges, inputString[index] - 'a');

    // Try changing the current character to maximize the cost
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == inputString[index]) continue;
        if (remainingChanges >= 1) {
            maxCostValue = max(maxCostValue, costMatrix[prevChar][ch - 'a'] + maxCost(index + 1, remainingChanges - 1, ch - 'a'));
        }
    }

    return dp[index][remainingChanges][prevChar] = maxCostValue;
}

void solve() {
    costMatrix.clear();
    costMatrix.resize(28, vector<int>(26, 0));
    
    int maxChanges;
    cin >> inputString >> maxChanges;

    int numCostValues;
    cin >> numCostValues;
    
    for (int i = 0; i < numCostValues; i++) {
        char char1, char2;
        int cost;
        cin >> char1 >> char2 >> cost;
        costMatrix[char1 - 'a'][char2 - 'a'] = cost;
    }
    memset(dp, -1, sizeof(dp));
    cout << maxCost(0, maxChanges, 27) << endl;  // Start with a dummy previous character
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