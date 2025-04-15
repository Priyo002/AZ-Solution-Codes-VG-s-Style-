#include <bits/stdc++.h>
using namespace std;

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

int arraySizeA, arraySizeB, kthElement;
vector<int> arrayA, arrayB;

// Checks if there are at least 'kthElement' pairs with sum <= currentSum
bool isValidSum(int currentSum) {
    int pairCount = 0;

    for (auto &valueA : arrayA) {
        if (valueA > currentSum) break;
        int validPairsWithB = upper_bound(arrayB.begin(), arrayB.end(), currentSum - valueA) - arrayB.begin();
        pairCount += validPairsWithB;
        if (pairCount >= kthElement){
            return true;
        }
    }

    return (pairCount >= kthElement);
}

void solve() {
    cin >> arraySizeA >> arraySizeB >> kthElement;

    arrayA.resize(arraySizeA);
    arrayB.resize(arraySizeB);

    for (int i = 0; i < arraySizeA; i++) cin >> arrayA[i];
    for (int i = 0; i < arraySizeB; i++) cin >> arrayB[i];

    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    if(arraySizeA > arraySizeB){
        swap(arraySizeA, arraySizeB);
        swap(arrayA,arrayB);
    }

    int low = arrayA[0] + arrayB[0];
    int high = arrayA[arraySizeA - 1] + arrayB[arraySizeB - 1];
    int result = high + 1;

    // Binary search to find the kth smallest sum
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isValidSum(mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << endl;
}

int32_t main() {

    fastIO();

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}