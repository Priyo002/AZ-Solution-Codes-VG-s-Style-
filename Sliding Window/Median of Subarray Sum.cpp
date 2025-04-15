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

int numElements, totalSubarrays, medianPosition;
vector<int> elements; 

// Check if there are at least 'medianPosition' subarrays with sum <= 'sum'
bool hasEnoughSubarrays(int sum) {
    int head = -1, tail = 0;
    int currentSum = 0;
    int count = 0;
    
    while (tail < numElements) {
        while (head + 1 < numElements && currentSum + elements[head + 1] <= sum) {
            head++;
            currentSum += elements[head];
        }
        count += (head - tail + 1);
        if (tail <= head) {
            currentSum -= elements[tail];
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
    return (count >= medianPosition);
}

// Solve each test case
void solve() {
    cin >> numElements;
    elements.resize(numElements);

    totalSubarrays = (numElements * (numElements + 1)) / 2;
    medianPosition = (totalSubarrays + 1) / 2;

    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    int low = *min_element(elements.begin(), elements.end());
    int high = accumulate(elements.begin(), elements.end(), 0LL);
    int medianScore = -1;

    // Binary search to find the median score
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (hasEnoughSubarrays(mid)) {
            medianScore = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << medianScore << endl;
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