#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 201;
 
int dp[N][N][N];
 
void precalc() {
    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                int prev = 0;
                if (i) prev = max(prev, dp[i - 1][j][k]);
                if (j) prev = max(prev, dp[i][j - 1][k]);
                if (k) prev = max(prev, dp[i][j][k - 1]);
                dp[i][j][k] = prev;
                int xr = ((i & 1) * 1) ^ ((j & 1) * 2) ^ ((k & 1) * 3);
                if (xr == 0 && (i || j || k)) {
                    ++dp[i][j][k];
                }
            }
        }
    }
}
 
void solve() {
    vector<int> cnt(4);
    for (int i = 0; i < 4; ++i) {
        cin >> cnt[i];
    }
    cout << dp[cnt[0]][cnt[1]][cnt[2]] + cnt[3] / 2 << '\n';
}
 
int main() {
    precalc();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}