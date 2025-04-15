#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Enable fast I/O
void fastIO() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n, k;
vector<int> boards;

// Check if painting is possible within 'maxTime' using at most k painters
bool isFeasible(int maxTime) {
	int painters = 1;
	int currentTime = 0;

	for (int i = 0; i < n; i++) {
		currentTime += boards[i];

		// If this board exceeds current maxTime, assign to new painter
		if (currentTime > maxTime) {
			painters++;
			currentTime = boards[i];
		}
	}

	return painters <= k;
}

// Binary search to find minimum possible time
void minTimeToPaint() {
	cin >> n >> k;

	boards.resize(n);
	for (int i = 0; i < n; i++) cin >> boards[i];

	int lo = *max_element(boards.begin(), boards.end());   // At least the largest board
	int hi = accumulate(boards.begin(), boards.end(), 0LL); // At most total sum

	int result = hi;

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;

		if (isFeasible(mid)) {
			result = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << result << endl;
}

int32_t main() {
	fastIO();

	int t;
	cin >> t;
	while (t--) {
		minTimeToPaint();
	}
}