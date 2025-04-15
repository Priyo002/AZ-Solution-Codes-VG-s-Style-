#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll int64_t

int n;
int dp[102][100010];
vector<int> temp,sum;

int f(int i,int left){
    if(i==n){
        if(left==0) return 1;
        else return 0;
    }

    if(dp[i][left]!=-1) return dp[i][left];

    int ans = f(i+1,left);
    if(left-sum[i]>=0){
        ans |= f(i+1,left-sum[i]);
    }
    return dp[i][left] = ans;
}

void generate(int i,int left){
    if(i==n) return;

    if(f(i+1,left)){
        generate(i+1,left);
    }
    else if(left-sum[i]>=0 && f(i+1,left-sum[i])){
        temp.push_back(i);
        generate(i+1,left-sum[i]);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    
    vector<vector<int>> ans;
    sum = arr;
    n = arr.size();

    memset(dp,-1,sizeof(dp));

    int q = queries.size();

    for(int i=0;i<q;i++){
        if(f(0,queries[i])){
            temp.clear();
            generate(0,queries[i]);
            ans.push_back(temp);
        }
        else{
            vector<int> k = {-1};
            ans.push_back(k);
        }
    }

    return ans;

}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}