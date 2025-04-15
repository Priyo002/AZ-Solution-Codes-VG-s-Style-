#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

// Check if mid is in the rotated part
bool isRotationPoint(vector<int>& arr, int mid) {
    return arr[0] > arr[mid];
}

// Finds and prints index of minimum element
void findMinIndex() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int low = 0, high = n - 1, minIndex = 0;
	while (low <= high) {
		int mid = low + (high - low) / 2;

		// If mid is in rotated part, potential minimum
		if (isRotationPoint(arr, mid)) {
			minIndex = mid;
			high = mid - 1;
		} else {
			// Search right half
			low = mid + 1;
		}
	}
	cout << minIndex << endl;
}

int32_t main() {
	fastIO();
	int t;
	cin >> t;
	while (t--) {
		findMinIndex();
	}
}