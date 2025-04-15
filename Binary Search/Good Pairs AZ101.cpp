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

void solveTestCase() {
    int length;
    cin >> length;

    vector<int> arrayA(length), arrayB(length);

    for (int i = 0; i < length; i++) cin >> arrayA[i];
    for (int i = 0; i < length; i++) cin >> arrayB[i];

    vector<int> differenceArray(length);

    for (int i = 0; i < length; i++) {
        differenceArray[i] = arrayA[i] - arrayB[i];
    }

    sort(differenceArray.begin(), differenceArray.end());

    int goodPairCount = 0;

    for (int i = 0; i < length; i++) {
        auto it = upper_bound(differenceArray.begin() + i + 1, differenceArray.end(), -differenceArray[i]);
        goodPairCount += (differenceArray.end() - it);
    }

    cout << goodPairCount << endl;
}

int32_t main() {

    fastIO();

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solveTestCase();
    }

    return 0;
}