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

// Function to find the maximum subarray sum using Kadane's algorithm
int getMaxSubarraySum(vector<int>& arr) {
    int maxSum = 0, currentSum = 0;
    for (auto x : arr) {
        currentSum += x;
        if (currentSum < 0) currentSum = 0;
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

void solve() {
    int numRows, numCols;
    cin >> numRows >> numCols;

    int grid[numRows][numCols];
    int hasPositive = 0;
    int maxElement = -INF;

    // Read the grid and check for positive elements
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> grid[i][j];
            if (grid[i][j] >= 0) hasPositive = 1;
            maxElement = max(maxElement, grid[i][j]);
        }
    }

    int maxSum = 0;
    if (hasPositive == 0) {
        // If no positive elements, the maximum sum is the largest element
        maxSum = maxElement;
        cout << maxSum << endl;
        return;
    }

    // Calculate the maximum sum subgrid
    if (numCols < numRows) {
        // Iterate over columns
        for (int leftCol = 0; leftCol < numCols; leftCol++) {
            vector<int> rowSum(numRows, 0);
            for (int rightCol = leftCol; rightCol < numCols; rightCol++) {
                for (int row = 0; row < numRows; row++) {
                    rowSum[row] += grid[row][rightCol];
                }
                maxSum = max(maxSum, getMaxSubarraySum(rowSum));
            }
        }
    } else {
        // Iterate over rows
        for (int topRow = 0; topRow < numRows; topRow++) {
            vector<int> colSum(numCols, 0);
            for (int bottomRow = topRow; bottomRow < numRows; bottomRow++) {
                for (int col = 0; col < numCols; col++) {
                    colSum[col] += grid[bottomRow][col];
                }
                maxSum = max(maxSum, getMaxSubarraySum(colSum));
            }
        }
    }
    cout << maxSum << endl;
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