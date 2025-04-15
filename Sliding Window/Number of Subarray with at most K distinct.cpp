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
    int numElements, maxDistinct;
    cin >> numElements >> maxDistinct;

    vector<int> elements(numElements);
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    int head = -1, tail = 0;
    int subarrayCount = 0;
    map<int, int> frequencyMap;

    // Use two pointers to find subarrays with at most maxDistinct distinct elements
    while (tail < numElements) {
        while (head + 1 < numElements && (frequencyMap.size() + 1 - frequencyMap.count(elements[head + 1])) <= maxDistinct) {
            head++;
            frequencyMap[elements[head]]++;
        }

        subarrayCount += (head - tail + 1);

        if (tail <= head) {
            frequencyMap[elements[tail]]--;
            if (frequencyMap[elements[tail]] == 0) frequencyMap.erase(elements[tail]);
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
    cout << subarrayCount << endl;
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