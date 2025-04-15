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

int numBalls, minColorsPerBasket;
map<int, int> colorFrequencyMap;

// Check if a given number of baskets can be filled
bool canFillBaskets(int numBaskets) {
    vector<int> colorCounts;
    for (auto color : colorFrequencyMap) {
        colorCounts.push_back(min(numBaskets, color.second));
    }

    int totalBallsUsed = accumulate(colorCounts.begin(), colorCounts.end(), 0);
    return (totalBallsUsed >= (numBaskets * minColorsPerBasket));
}

// Solve each test case
void solve() {
    cin >> numBalls >> minColorsPerBasket;
    colorFrequencyMap.clear();

    for (int i = 0; i < numBalls; i++) {
        int color;
        cin >> color;
        colorFrequencyMap[color]++;
    }

    int low = 0, high = numBalls / minColorsPerBasket;
    int maxFilledBaskets = -1;

    // Binary search for the maximum number of filled baskets
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canFillBaskets(mid)) {
            maxFilledBaskets = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << maxFilledBaskets << endl;
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