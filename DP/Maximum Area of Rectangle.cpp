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

// Function to calculate the largest rectangle area in a histogram
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> nextSmaller(n, n), prevSmaller(n, -1);
    stack<int> st;

    // Find the next smaller element index for each bar
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nextSmaller[i] = st.top();
        }
        st.push(i);
    }

    // Find the previous smaller element index for each bar
    stack<int> st1;
    st1.push(0);
    for (int i = 1; i < n; i++) {
        while (!st1.empty() && heights[st1.top()] >= heights[i]) {
            st1.pop();
        }
        if (!st1.empty()) {
            prevSmaller[i] = st1.top();
        }
        st1.push(i);
    }

    // Calculate the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

void solve() {
    int numRows, numCols;
    cin >> numRows >> numCols;

    int grid[numRows][numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> height(numRows, 0);
    int maxRectangleArea = 0;

    // Calculate the maximum rectangle area for each row as the base
    for (int j = 0; j < numCols; j++) {
        for (int i = 0; i < numRows; i++) {
            if (grid[i][j] == 0) {
                height[i] = 0;
            } else {
                height[i]++;
            }
        }
        maxRectangleArea = max(maxRectangleArea, largestRectangleArea(height));
    }
    cout << maxRectangleArea << endl;
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