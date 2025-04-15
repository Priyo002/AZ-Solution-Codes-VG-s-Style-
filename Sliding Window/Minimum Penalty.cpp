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

// Solve each test case
void solve() {
    int numElements, subarrayLength;
    cin >> numElements >> subarrayLength;

    vector<int> elements(numElements);
    for (int &element : elements) {
        cin >> element;
    }

    map<int, int> frequencyMap;
    int minPenalty = INT_MAX;

    // Sliding window to find subarray with minimum distinct elements
    for (int i = 0; i < numElements; i++) {
        // Add current element to the frequency map
        frequencyMap[elements[i]]++;

        // Remove the element that is sliding out of the window
        if (i - subarrayLength >= 0) {
            frequencyMap[elements[i - subarrayLength]]--;
            if (frequencyMap[elements[i - subarrayLength]] == 0) {
                frequencyMap.erase(elements[i - subarrayLength]);
            }
        }

        // Update the minimum penalty for valid subarrays
        if (i >= subarrayLength - 1) {
            minPenalty = min(minPenalty, (int)frequencyMap.size());
        }
    }

    cout << minPenalty << endl;
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