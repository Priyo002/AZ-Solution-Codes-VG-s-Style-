#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'

const int MOD = 1e9 + 7;
const long long INF = 1e18;

// Enable fast I/O
void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int arrayLength, maxFlipsAllowed;
vector<int> binaryArray;

// Checks if there's a subarray of length 'windowSize' with at most 'maxFlipsAllowed' zeros
bool isPossible(int windowSize) {
    int zeroCount = 0;
    int minZeroInWindow = 1e9;

    for (int i = 0; i < arrayLength; i++) {
        zeroCount += (binaryArray[i] == 0);
        if (i - windowSize >= 0)
            zeroCount -= (binaryArray[i - windowSize] == 0);
        if (i >= windowSize - 1)
            minZeroInWindow = min(minZeroInWindow, zeroCount);
    }

    return minZeroInWindow <= maxFlipsAllowed;
}

void solveTestCase() {
    cin >> arrayLength >> maxFlipsAllowed;

    binaryArray.clear();
    binaryArray.resize(arrayLength);

    for (int i = 0; i < arrayLength; i++) {
        cin >> binaryArray[i];
    }

    int low = 0, high = arrayLength;
    int maxLength = -1;

    // Binary search for the longest window with at most K zeros
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(mid)) {
            maxLength = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << maxLength << endl;
}

int32_t main() {
    
    fastIO();

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solveTestCase();
    }

    return 0;
}