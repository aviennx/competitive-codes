#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define vc vector
#define pii pair <int, int>
#define int long long
#define yesno(x) cout << ((x) ? "YES" : "NO")
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vc<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vc<vc<int>> dp(n + 1, vc<int>(m + 1, LLONG_MAX));
    for(int k = 0; k <= m; k++) {
        dp[0][k] = 0;
    }
    for(int pos = 1; pos <= n; pos++) {
        for(int k = 1; k <= m; k++) {
            if(pos > 0 && dp[pos-1][k] != LLONG_MAX)
                dp[pos][k] = dp[pos-1][k];
            if(k > 1 && dp[pos][k-1] != LLONG_MAX)
                dp[pos][k] = min(dp[pos][k], dp[pos][k-1]);
            int sum = 0;
            for(int j = pos; j > 0; j--) {
                sum += a[j-1];
                if(sum > b[k-1]) break;
                
                if(dp[j-1][k] != LLONG_MAX) {
                    dp[pos][k] = min(dp[pos][k], dp[j-1][k] + m - k);
                }
            }
        }
    }
    
    int ans = LLONG_MAX;
    for(int k = 1; k <= m; k++) {
        ans = min(ans, dp[n][k]);
    }
    
    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
}

int32_t main() {
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    
    int t = 1;
    cin >> t;
    for(int test_case = 1; test_case <= t; test_case++) {
        solve();
    }
    return 0;
}