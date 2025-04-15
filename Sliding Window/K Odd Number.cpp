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

int numElements, maxOdds, maxSum;
vector<int> elements, prefixSum;
int maxSubarraySum;

void solve() {
    cin >> numElements >> maxOdds >> maxSum;

    maxSubarraySum = INT_MIN;

    elements.clear();
    prefixSum.clear();

    elements.resize(numElements);
    prefixSum.resize(numElements);

    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
        prefixSum[i] = elements[i];
    }

    for (int i = 1; i < numElements; i++) {
        prefixSum[i] += prefixSum[i - 1];
    }

    int head = -1, tail = 0;
    int oddCount = 0;
    multiset<int> prefixSet;

    // Sliding window to find the maximum subarray sum with constraints
    while (tail < numElements) {
        while (head + 1 < numElements && (oddCount + (elements[head + 1] % 2 != 0) <= maxOdds)) {
            head++;
            prefixSet.insert(prefixSum[head]);
            if (elements[head] % 2 != 0) oddCount++;
        }

        int adjustedMaxSum = maxSum;
        if (tail) adjustedMaxSum += prefixSum[tail - 1];

        auto it = prefixSet.upper_bound(adjustedMaxSum);

        if (it != prefixSet.begin()) {
            it--;
            int currentSum = *it;
            if (tail) currentSum -= prefixSum[tail - 1];
            maxSubarraySum = max(maxSubarraySum, currentSum);
        }

        if (tail <= head) {
            if (elements[tail] % 2 != 0) oddCount--;
            prefixSet.erase(prefixSet.find(prefixSum[tail]));
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }

    if (maxSubarraySum != INT_MIN) {
        cout << maxSubarraySum;
    } else {
        cout << "IMPOSSIBLE";
    }
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