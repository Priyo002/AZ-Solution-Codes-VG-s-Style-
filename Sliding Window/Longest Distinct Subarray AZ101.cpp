#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const long long INF = 1e18;

// Enable fast I/0
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
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    int head = -1, tail = 0;
    int maxLength = 1;
    set<int> distinctElements;

    // Use two pointers to find the longest subarray with distinct elements
    while (tail < numElements) {
        while (head + 1 < numElements && distinctElements.count(elements[head + 1]) == 0) {
            head++;
            distinctElements.insert(elements[head]);
        }

        maxLength = max(maxLength, (head - tail + 1));

        if (tail <= head) {
            distinctElements.erase(elements[tail]);
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
    cout << maxLength << endl;
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