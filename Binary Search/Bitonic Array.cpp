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

vector<int> arr;
int n, q;

// Check if current index is in the decreasing part (or at the end)
bool isPeakOrRight(int mid) {
	if (mid == n - 1) return true;
	return arr[mid] > arr[mid + 1];
}

// Binary search in increasing part
int binarySearchInc(int low, int high, int key) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == key) return mid;
		else if (arr[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

// Binary search in decreasing part
int binarySearchDec(int low, int high, int key) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == key) return mid;
		else if (arr[mid] < key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

void processTestCase() {
	cin >> n >> q;
	arr.clear();
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// Find peak of bitonic array
	int low = 0, high = n - 1, peakIndex = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPeakOrRight(mid)) {
			peakIndex = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	while (q--) {
		int key;
		cin >> key;

		int idx1 = binarySearchInc(0, peakIndex, key);
		int idx2 = binarySearchDec(peakIndex + 1, n - 1, key);

		// Output 1-based indices
		if (idx1 != -1) cout << idx1 + 1 << " ";
		if (idx2 != -1) cout << idx2 + 1;
		cout << endl;
	}
}

int32_t main() {
	fastIO();
	int t;
	cin >> t;
	while (t--) {
		processTestCase();
	}
}