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

// Calculate sum of digits of a number
int digitSum(int num) {
	string str = to_string(num);
	int sum = 0;
	for (auto ch : str) sum += (ch - '0');
	return sum;
}

// Check if (X - sum_of_digits(X)) ≥ S
bool isValid(int x, int s) {
	return (x - digitSum(x)) >= s;
}

// Find number of valid X in [1, N] such that (X - sum_of_digits(X)) ≥ S
void countValidNumbers() {
	int n, s;
	cin >> n >> s;

	int low = 1, high = n, firstValid = high + 1;

	// Binary search for smallest valid X
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isValid(mid, s)) {
			firstValid = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	firstValid--; // Last invalid

	// Total valid numbers = [firstValid+1, N] → (N - firstValid)
	cout << n - firstValid << endl;
}

int32_t main() {
	fastIO();

	int t;
	cin >> t;
	while (t--) {
		countValidNumbers();
	}
}