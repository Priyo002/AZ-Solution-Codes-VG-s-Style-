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

int arraySize;
vector<int> nums;

// Function to find the maximum product subarray
void solve() {
    cin >> arraySize;
    
    nums.clear();
    nums.resize(arraySize);

    for (int i = 0; i < arraySize; i++) cin >> nums[i];

    int maxProduct = LLONG_MIN, currentMax = 1, currentMin = 1;

    for (int i = 0; i < arraySize; i++) {
        int tempMax = currentMax;
        // Update currentMax and currentMin considering the current element
        currentMax = max({nums[i], currentMin * nums[i], currentMax * nums[i]});
        currentMin = min({nums[i], currentMin * nums[i], tempMax * nums[i]});
        // Update the global maximum product
        maxProduct = max(maxProduct, currentMax);
    }
    
    cout << maxProduct << endl;
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