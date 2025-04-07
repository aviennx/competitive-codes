#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")

const int N = 2e5 + 5;

int n, k;
pair<int, int> arr[1005] = {};
vector<vector<int>> dp2;
vector<vector<int>> dp;

int fun(int idx, int d) {
    if (d == 0)
        return 0ll;
    if (idx == 0 || d < 0)
        return INT_MAX;
    if (dp2[idx][d] != -1)
        return dp2[idx][d];
    auto [a, b] = arr[idx - 1];
    int ans= INT_MAX;
    for (int i = 0; i <= d; i++) {
        if (a < i)
            continue;
        if(d > b + i)
            continue;
        ans = min(ans, i * b + (d - i) * a - i * (d - i));
    }
    return dp2[idx][d] = ans;
}

int calc(int idx, int rem) {
    if (idx == n)
        if(rem == 0)
            return 0ll;
    if (idx == n || rem < 0)
        return INT_MAX;
    if (dp[idx][rem] != -1)
        return dp[idx][rem];
    int ans = INT_MAX;
    for (int i = 0; i <= rem; i++) {
        ans = min(ans, calc(idx + 1, rem - i) + fun(idx + 1, i));
    }
    return dp[idx][rem] = ans;
}

void solve(){
    cin >> n >> k;
    dp2.resize(n + 1, vector<int>(k + 1, -1));
    dp.resize(n + 1, vector<int>(k + 1, -1));
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    int ans = calc(0, k);
    if (ans == INT_MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
int32_t main() {
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}