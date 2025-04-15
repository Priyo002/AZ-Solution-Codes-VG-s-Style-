#include <bits/stdc++.h>
using namespace std;

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
    int numElements;
    cin >> numElements;

    vector<int> elements(numElements);
    unordered_set<int> distinctElements;

    // Read the array and find all distinct elements
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
        distinctElements.insert(elements[i]);
    }

    int totalDistinct = distinctElements.size();
    int head = -1, tail = 0;
    int minLength = INT_MAX;
    map<int, int> frequencyMap;

    // Use two pointers to find the smallest subarray containing all distinct elements
    while (tail < numElements) {
        while (head + 1 < numElements && (frequencyMap.size() + 1 - frequencyMap.count(elements[head + 1]) <= totalDistinct)) {
            head++;
            frequencyMap[elements[head]]++;
            if (frequencyMap.size() == totalDistinct) break;
        }

        // Update the minimum length for valid subarrays
        while (tail <= head && frequencyMap.size() == totalDistinct) {
            minLength = min(minLength, head - tail + 1);
            frequencyMap[elements[tail]]--;
            if (frequencyMap[elements[tail]] == 0) frequencyMap.erase(elements[tail]);
            tail++;
        }

        if (tail <= head) {
            frequencyMap[elements[tail]]--;
            if (frequencyMap[elements[tail]] == 0) frequencyMap.erase(elements[tail]);
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
    cout << minLength << endl;
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