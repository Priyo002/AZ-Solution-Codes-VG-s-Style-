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

typedef long double ld;

int numElements, numIndicesToSelect;
vector<int> arrayA, arrayB;

// Function to check if a given mid value can achieve the desired condition
bool isFeasible(ld mid) {
    // Min-heap to store the smallest differences
    priority_queue<ld, vector<ld>, greater<ld>> minHeap;
    
    // Calculate the difference for each element and maintain the top K differences
    for (int i = 0; i < numElements; i++) {
        minHeap.push(arrayA[i] - mid * arrayB[i]);
        if (minHeap.size() > numIndicesToSelect) {
            minHeap.pop();
        }
    }

    // Sum the top K differences
    ld sumDifferences = 0.0;
    while (!minHeap.empty()) {
        sumDifferences += minHeap.top();
        minHeap.pop();
    }
    
    // Check if the sum of differences is non-negative
    return sumDifferences >= 0.0;
}


void solve() {
   
    cin >> numElements >> numIndicesToSelect;

    arrayA.resize(numElements);
    arrayB.resize(numElements);

    for (int i = 0; i < numElements; i++) {
        cin >> arrayA[i];
    }

    for (int i = 0; i < numElements; i++) {
        cin >> arrayB[i];
    }

    // Initialize the binary search bounds
    ld low = 0.0, high = 1e8;
    ld optimalRatio = 0.0;

    // Perform binary search to find the maximum possible ratio
    while (abs(low - high) > 1e-9) {
        ld mid = (low + high) / 2.0;

        // Check if the current mid value is feasible
        if (isFeasible(mid)) {
            optimalRatio = mid;
            low = mid;
        } else {
            high = mid;
        }
    }

    // Output the result rounded to 6 decimal places
    cout << fixed << setprecision(6) << optimalRatio << "\n";
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