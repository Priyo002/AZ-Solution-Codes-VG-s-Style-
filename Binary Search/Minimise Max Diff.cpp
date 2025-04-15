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

int n, k;
int a[100200];

// Check if we can insert at most k points to ensure no segment > maxGap
bool isFeasible(int maxGap) {
	int used = 0;
	for (int i = 1; i < n; i++) {
		// Count how many points needed in segment [a[i-1], a[i]]
		int gap = a[i] - a[i - 1];
		used += (gap + maxGap - 1) / maxGap - 1;
	}
	return used <= k;
}

void minimizeMaxGap() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	int lo = 1, hi = 0;
	for (int i = 1; i < n; i++) {
		hi = max(hi, a[i] - a[i - 1]);  // max initial gap
	}

	int answer = hi;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (isFeasible(mid)) {
			answer = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << answer << endl;
}

int32_t main() {
	fastIO();

	int t;
	cin >> t;
	while (t--) {
		minimizeMaxGap();
	}
}