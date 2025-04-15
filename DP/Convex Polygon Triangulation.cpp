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

int numVertices;
int vertexValues[10010];
int dp[101][101];

// Function to calculate the minimum triangulation score
int minTriangulationScore(int left, int right) {
    if (left + 1 == right) return 0;  // No triangle can be formed

    if (dp[left][right] != -1) return dp[left][right];

    int minScore = INF;
    // Try all possible points to form a triangle with vertices at 'left' and 'right'
    for (int k = left + 1; k <= right - 1; k++) {
        int score = vertexValues[left] * vertexValues[k] * vertexValues[right] + 
                    minTriangulationScore(left, k) + 
                    minTriangulationScore(k, right);
        minScore = min(minScore, score);
    }

    return dp[left][right] = minScore;
}

void solve() {
    cin >> numVertices;

    for (int i = 0; i < numVertices; i++) {
        cin >> vertexValues[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << minTriangulationScore(0, numVertices - 1) << endl;
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