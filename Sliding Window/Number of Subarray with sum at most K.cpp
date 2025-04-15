#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const long long INF = 1e18;

// Enable fast I/O
void init() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// Solve each test case
void solve() {
    int numElements, maxSum;
    cin >> numElements >> maxSum;

    vector<int> elements(numElements);
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    int head = -1, tail = 0;
    int subarrayCount = 0, currentSum = 0;

    // Use two pointers to find subarrays with sum <= maxSum
    while (tail < numElements) {
        while (head + 1 < numElements && currentSum + elements[head + 1] <= maxSum) {
            head++;
            currentSum += elements[head];
        }

        subarrayCount += (head - tail + 1);

        if (tail <= head) {
            currentSum -= elements[tail];
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
    cout << subarrayCount << endl;
}

int32_t main() {
    init();

    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}