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

string inputString;
int dictionarySize;
set<string> dictionary;
int dp[301];

// Function to check if the string can be segmented into dictionary words
bool canSegment(int index) {
    if (index == inputString.size()) return true;
    if (dp[index] != -1) return dp[index];

    string currentWord = "";
    for (int j = index; j < inputString.size(); j++) {
        currentWord += inputString[j];
        if (dictionary.find(currentWord) != dictionary.end() && canSegment(j + 1)) {
            return dp[index] = true;
        }
    }
    return dp[index] = false;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    dictionary.clear();

    cin >> dictionarySize;
    cin >> inputString;

    for (int i = 0; i < dictionarySize; i++) {
        string word;
        cin >> word;
        dictionary.insert(word);
    }

    if (canSegment(0)) cout << "Yes";
    else cout << "No";
    cout << endl;
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