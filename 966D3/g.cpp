#include <bits/stdc++.h>

using namespace std;

int dp[1005][105];
int cost[1005][105];

void solve() {
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        cost[i][0] = 0;
        for(int p = 1; p <= k; p++) {
            cost[i][p] = 1e9;
            for(int r = 0; r <= p; r++) {
                int c = p - r;
                if(r > a || c > b) continue;
                cost[i][p] = min(cost[i][p], r * b + c * a - r * c);
            }
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) dp[i][j] = 1e9;
    }
    
    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int t = j; t <= k; t++) {
                dp[i + 1][t] = min(dp[i + 1][t], dp[i][j] + cost[i + 1][t - j]);
            }
        }
    }

    if(dp[n][k] == 1e9) dp[n][k] = -1;
    cout << dp[n][k] << '\n';
}

int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
